{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "bitmap.cc" ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")",
        "/usr/include/freetype2"
      ],
      "link_settings": {
        'libraries': ["-L/usr/include/freetype2", "-lfreetype" ],
      },
    }
  ]
}

