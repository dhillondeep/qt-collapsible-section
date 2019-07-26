# QT: Collapsible Section

This is a simple collapsable section for QT5.

Special thanks to "x squared" who has posted the original code for this idea at StackOverflow: http://stackoverflow.com/a/37119983/2573127

**Note:** This project has built upon the initial codebase to transform this into a CMake library. This library can be used by other Qt CMake projects.

## Sample Usage
* Clone or submodule this repository
* Using CMake include the directory and add it as a subdirectory
* Using CMake link the library with main target

```cmake
add_subdirectory(qt-section-widget)
target_include_directories(${PROJECT_NAME} PRIVATE qt-section-widget)
target_link_libraries(${PROJECT_NAME} PRIVATE qt-section-widget)
```

An example of this can be seen inside the **example** folder.

## Sample Code

    Section* section = new Section("Section", 300, parentWidget);
    auto* anyLayout = new QVBoxLayout();
    anyLayout->addWidget(new QLabel("Some Text in Section", section));
    anyLayout->addWidget(new QPushButton("Button in Section", section));

    section->setContentLayout(anyLayout);

## Sample Animation

![section opening and closing](example.gif)
