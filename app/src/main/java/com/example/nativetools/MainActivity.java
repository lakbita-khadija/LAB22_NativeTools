package com.example.nativetools;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    public native String getNativeMessage();
    public native int computePower(int base, int exponent);
    public native String convertToUpper(String text);
    public native double calculateAverage(int[] values);

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tvMessage = findViewById(R.id.tvMessage);
        TextView tvPower = findViewById(R.id.tvPower);
        TextView tvUpper = findViewById(R.id.tvUpper);
        TextView tvAverage = findViewById(R.id.tvAverage);

        tvMessage.setText(getNativeMessage());

        int power = computePower(3, 4);
        tvPower.setText("Puissance 3^4 = " + power);

        String upper = convertToUpper("android jni");
        tvUpper.setText("Texte transformé : " + upper);

        int[] values = {12, 16, 18, 20, 24};
        double avg = calculateAverage(values);
        tvAverage.setText("Moyenne du tableau = " + avg);
    }
}