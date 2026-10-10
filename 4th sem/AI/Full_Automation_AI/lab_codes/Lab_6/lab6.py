import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder
from sklearn.naive_bayes import GaussianNB
print("=" * 60)
print("        MCP NEURON: LOGIC GATES")
print("        Program by: Prashidda Rai")
print("        Roll No: 22")
print("=" * 60)

# Create dataset
data = {
    'Outlook': ['Rainy', 'Rainy', 'Overcast', 'Sunny', 'Sunny', 'Sunny',
                'Overcast', 'Rainy', 'Rainy', 'Sunny', 'Rainy', 'Overcast',
                'Overcast', 'Sunny'],
    'Temp': ['Hot', 'Hot', 'Hot', 'Mild', 'Cool', 'Cool', 'Cool',
             'Mild', 'Cool', 'Mild', 'Mild', 'Mild', 'Hot', 'Mild'],
    'Humidity': ['High', 'High', 'High', 'High', 'Normal', 'Normal',
                 'Normal', 'High', 'Normal', 'Normal', 'Normal',
                 'High', 'Normal', 'High'],
    'Wind': ['FALSE', 'TRUE', 'FALSE', 'FALSE', 'FALSE', 'TRUE',
             'TRUE', 'FALSE', 'FALSE', 'FALSE', 'TRUE', 'TRUE',
             'FALSE', 'FALSE'],
    'Rain': ['No', 'No', 'Yes', 'Yes', 'Yes', 'No', 'Yes',
             'No', 'Yes', 'Yes', 'Yes', 'Yes', 'Yes', 'No']
}

df = pd.DataFrame(data)

# Encode categorical data
le_outlook = LabelEncoder()
le_temp = LabelEncoder()
le_humidity = LabelEncoder()
le_wind = LabelEncoder()
le_rain = LabelEncoder()

outlook_enc = le_outlook.fit_transform(df['Outlook'])
temp_enc = le_temp.fit_transform(df['Temp'])
humidity_enc = le_humidity.fit_transform(df['Humidity'])
wind_enc = le_wind.fit_transform(df['Wind'])
rain_enc = le_rain.fit_transform(df['Rain'])

# Prepare features and target
X = np.array(list(zip(outlook_enc, temp_enc,
                      humidity_enc, wind_enc)))
y = np.array(rain_enc)

# Train Naive Bayes model
model = GaussianNB()
model.fit(X, y)

# Predict for Sunny, Hot, Normal, FALSE
today = [[2, 1, 1, 0]]

pred = model.predict(today)
prob = model.predict_proba(today)

print("Prediction for (Sunny, Hot, Normal, FALSE):")
print(f"Prediction: {'RAIN' if pred[0] == 1 else 'NO RAIN'}")
print(f"Probability of Rain: {prob[0][1]:.2%}")
print(f"Probability of No Rain: {prob[0][0]:.2%}")