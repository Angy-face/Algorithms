import tkinter as tk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk
import torch
import torch.nn as nn
import torchvision.transforms as transforms
from torchvision.models import resnet50

class CustomResNet(nn.Module):
    def __init__(self, num_class=5, h_dims=[]):
        super(CustomResNet, self).__init__()

        self.resnet = resnet50(pretrained=True)

        for param in self.resnet.parameters():
            param.requires_grad = True

        in_features = self.resnet.fc.in_features
        self.resnet.fc = nn.Identity() 

        self.class_classifier = self._create_classifier(in_features, h_dims, num_class)

    def _create_classifier(self, in_features, h_dims, num_classes):
        layers = []
        for hdim in h_dims:
            layers.append(nn.Linear(in_features, hdim))
            layers.append(nn.ReLU(inplace=True))
            layers.append(nn.Dropout(p=0.30))
            in_features = hdim
        layers.append(nn.Linear(in_features, num_classes))
        return nn.Sequential(*layers)

    def forward(self, x):
        x = self.resnet(x)  
        class_output = self.class_classifier(x)
        return class_output
    
# Load the saved model
model = CustomResNet(num_class= 4,h_dims=[1024,512,512,256])
model.load_state_dict(torch.load('C:/Users/ASUS/NextgenAI/Projects/ABCC.pth'))
torch.save(model,'C:/Users/ASUS/NextgenAI/Projects/Model.pth')
model.eval()  # Set the model to evaluation mode

# Preprocess the image to match model input format
def preprocess_image(image_path):
    img = Image.open(image_path)
    
    if img.mode == 'RGBA':
        img = img.convert('RGB')
        
    transform = transforms.Compose([
        transforms.Resize((512,512)),
        transforms.ToTensor(),
        transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
    ])
    img_tensor = transform(img).unsqueeze(0)
    return img_tensor

# Function to classify the uploaded image
Cancer_Type = ['adenocarcinoma_left.lower.lobe', 'large.cell.carcinoma_left.hilum', 'normal', 'squamous.cell.carcinoma_left.hilum']
def classify_image():
    file_path = filedialog.askopenfilename(filetypes=[("Image Files", "*.png;*.jpg")])
    if file_path:
        img_tensor = preprocess_image(file_path)
        with torch.no_grad():
            output = model(img_tensor)
            _, predicted_class = torch.max(output, 1)
            result_label.config(text=f"Predicted Class: {Cancer_Type[predicted_class.item()]}")
        img = Image.open(file_path)
        img.thumbnail((400, 400))
        img_tk = ImageTk.PhotoImage(img)
        image_label.config(image=img_tk)
        image_label.image = img_tk  # Save reference to the image to prevent garbage collection
    else:
        messagebox.showinfo("Info", "No file selected")

# Tkinter app setup
window = tk.Tk()
window.title('CT_SCAN Classifier')
window.minsize(width=500, height=500)

# Upload button
upload_button = tk.Button(window, text="Upload and Classify Image", command=classify_image)
upload_button.pack()

# Label to display image
image_label = tk.Label(window)
image_label.pack()

# Label to display classification result
result_label = tk.Label(window, text="Result will be shown here")
result_label.pack()

window.mainloop()