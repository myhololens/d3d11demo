# Direct3D 11演示
这是为了测试[乘风龙王的代码库(c++)](https://github.com/cflw/cflw_cpp)的**cflw图形_d3d11**是否可用而写的代码。


项目依赖项：
* [乘风龙王的代码库(c++)](https://github.com/cflw/cflw_cpp)

## 内容包含
我把有的没的想要做的都列出来了，没有的以后补上。

### 基础
* **空白窗口**：创建一个窗口并初始化d3d11设备。同时作为下面代码的模板。
* **简单三角形**：使用顶点着色器和像素着色器画一个三角形
* **简单立方体**：画一个不断旋转的立方体
* **二维文本**：与Direct2D混合渲染。

### 基础+
* **纹理立方体**：画一个带纹理、不断旋转的立方体。纹理和模型来自外部文件。
* **简单光**：离光远的像素暗。
* **简单雾**：离镜头远的像素暗。
* **深度模板**：不同深度的三角形放在一起，前面遮住后面，中间放一个圆形遮罩。
* **粒子**：使用几何着色器画粒子。

### 进阶
* **高级光**：用不同的光画出立方体表面。
* **光影**：画物体阴影
* **边框**：使用几何着色器画物体边缘
* **曲面细分**：使用外壳着色器和域着色器画光滑曲面。

### 高级&特效

* *没想好要做什么*