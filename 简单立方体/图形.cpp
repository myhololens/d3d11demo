#include "图形.h"
#include "常量.h"
void C图形::f初始化(HWND a窗口) {
	m三维.f初始化(a窗口);
	m窗口大小 = m三维.fg窗口大小();
	auto &v渲染控制 = m三维.fg渲染控制();
	auto &v渲染状态 = m三维.fg渲染状态();
	auto &v着色器工厂 = m三维.fg着色器工厂();
	auto &v缓冲工厂 = m三维.fg缓冲工厂();
	三维::C顶点格式 v顶点格式;
	三维::tp输入布局 v输入布局;
	v顶点格式.f添加(三维::C顶点格式::e位置, 3);
	v顶点格式.f添加(三维::C顶点格式::e颜色, 4);
	v着色器工厂.f编译并创建顶点着色器(m着色器v, L"着色器.hlsl", "vs", v输入布局, v顶点格式);
	v着色器工厂.f编译并创建像素着色器(m着色器p, L"着色器.hlsl", "ps");
	v渲染控制.fs顶点着色器(m着色器v.Get());
	v渲染控制.fs像素着色器(m着色器p.Get());
	v渲染控制.fs输入布局(v输入布局.Get());
	//顶点
	struct S顶点 {
		数学::S向量3 m坐标;
		数学::S颜色 m颜色;
	};
	const S顶点 va顶点[] = {
		{{-1, -1, -1}, {1, 0, 0, 1}},	//0
		{{-1, -1, 1}, {0, 1, 0, 1}},	//1
		{{-1, 1, -1}, {0, 0, 1, 1}},	//2
		{{-1, 1, 1}, {1, 1, 0, 1}},		//3
		{{1, -1, -1}, {1, 1, 0, 1}},	//4
		{{1, -1, 1}, {0, 0, 1, 1}},		//5
		{{1, 1, -1}, {0, 1, 0, 1}},		//6
		{{1, 1, 1}, {1, 0, 0, 1}}		//7
	};
	三维::tp缓冲 v顶点缓冲;
	v缓冲工厂.f创建缓冲(v顶点缓冲, va顶点, sizeof(va顶点), 三维::E缓冲::e顶点);
	v渲染控制.fs顶点缓冲(v顶点缓冲.Get(), sizeof(S顶点));
	//索引
	const uint16_t va索引[] = {
		2, 1, 0,
		2, 3, 1,
		4, 5, 6,
		5, 7, 6,
		0, 1, 4,
		1, 5, 4,
		6, 3, 2,
		6, 7, 3,
		4, 2, 0,
		4, 6, 2,
		1, 3, 5,
		3, 7, 5
	};
	三维::tp缓冲 v索引缓冲;
	v缓冲工厂.f创建缓冲(v索引缓冲, va索引, sizeof(va索引), 三维::E缓冲::e索引);
	v渲染控制.fs索引缓冲(v索引缓冲.Get());
	//固定
	m总矩阵[0] = m世界.ft矩阵4();
	数学::S相机 v相机;
	v相机.m坐标 = {0, 0, 4};
	v相机.m目标 = {0, 0, 0};
	v相机.m上方 = {0, 1, 0};
	m总矩阵[1] = v相机.ft矩阵4r();
	数学::S投影 v投影;
	v投影 = 数学::S投影(m窗口大小.x, m窗口大小.y);
	m总矩阵[2] = v投影.ft矩阵4r();
	v缓冲工厂.f创建缓冲(m固定, m总矩阵, sizeof(m总矩阵), 三维::E缓冲::e固定);
	v渲染控制.fs固定缓冲(0, m固定.Get());
	//其它状态
	v渲染控制.fs图元拓扑(三维::E图元拓扑::e列表三角形);
	v渲染控制.fs光栅化(v渲染状态.m光栅化.m默认.Get());
	v渲染控制.fs混合(v渲染状态.m混合.m开启透明.Get());
	v渲染控制.fs深度模板(v渲染状态.m深度模板.m正常深度r.Get());
}
void C图形::f销毁() {
	m着色器v.Reset();
	m着色器p.Reset();
	m三维.f销毁();
}
void C图形::f计算() {
	m世界.m旋转.x += c帧秒 * 0.9f;
	m世界.m旋转.y += c帧秒 * 0.5f;
	m世界.m旋转.z += c帧秒 * 0.2f;
}
void C图形::f更新() {
	auto &v渲染控制 = m三维.fg渲染控制();
	m总矩阵[0] = m世界.ft矩阵4();
	v渲染控制.f更新资源(m固定.Get(), m总矩阵);
}
void C图形::f显示() {
	auto &v渲染控制 = m三维.fg渲染控制();
	v渲染控制.f清屏();
	v渲染控制.f绘制索引(36);
	v渲染控制.f显示();
}