//
// Created by linwei on 2/5/21.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glog/logging.h>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        LOG(ERROR) << "Failed to create GLFW window";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        LOG(INFO) << "Failed to initialize GLEW";
        return -1;
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    glViewport(0, 0, width, height);

    //注册键盘事件
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window)) {
        //! poll event
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //! swap buffer
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    LOG(INFO) << "terminate";
    return 0;
}


void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    // 当用户按下ESC键,我们设置window窗口的WindowShouldClose属性为true
    // 关闭应用程序
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else {
        LOG(INFO) << "key: " << key << " pressed";
    }
}