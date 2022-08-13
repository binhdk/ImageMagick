package com.binh.imagemagick

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        System.loadLibrary("android-magick")

        Thread {
            convertWebpToGif(filesDir.path + "/152.webp", filesDir.path + "/152.gif")
        }.start()
    }

    external fun convertWebpToGif(webp: String, gif: String): Boolean
}