#include "图形.h"
void C图形::f初始化(HWND a窗口) {
	m三维.f初始化(a窗口);
	auto &v渲染控制 = m三维.fg渲染控制();
	auto &v渲染状态 = m三维.fg渲染状态();
	auto &v着色器工厂 = m三维.fg着色器工厂();
	auto &v缓冲工厂 = m三维.fg缓冲工厂();
	三维::C顶点格式 v顶点格式;
	三维::tp输入布局 v输入布局;
	v顶点格式.f添加(三维::C顶点格式::e位置, 2);
	v顶点格式.f添加(三维::C顶点格式::e颜色, 4);
	v着色器工厂.f编译并创建顶点着色器(m着色器v, L"着色器.hlsl", "vs", v输入布局, v顶点格式);
	v着色器工厂.f编译并创建像素着色器(m着色器p, L"着色器.hlsl", "ps");
	v渲染控制.fs顶点着色器(m着色器v.Get());
	v渲染控制.fs像素着色器(m着色器p.Get());
	v渲染控制.fs输入布局(v输入布局.Get());
	struct S顶点 {
		数学::S向量2 m坐标;
		数学::S颜色 m颜色;
	};
	const S顶点 va顶点[] = {
		{数学::S向量2(0, 0.5f), 数学::S颜色(1, 0, 0)},
		{数学::S向量2(0.5f, -0.5f), 数学::S颜色(0, 1, 0)},
		{数学::S向量2(-0.5f, -0.5f), 数学::S颜色(0, 0, 1)}
	};
	三维::tp缓冲 v顶点缓冲;
	v缓冲工厂.f创建缓冲(v顶点缓冲, va顶点, sizeof(va顶点), 三维::E缓冲::e顶点);
	v渲染控制.fs顶点缓冲(v顶点缓冲.Get(), sizeof(S顶点));
	v渲染控制.fs光栅化(v渲染状态.m光栅化.m显示隐藏面.Get());
	v渲染控制.fs混合(v渲染状态.m混合.m开启透明.Get());
	v渲染控制.fs深度模板(v渲染状态.m深度模板.m正常深度r.Get());
	//二维
	m二维.f初始化_设备(m三维.fg基础设备().Get());
	m二维.f初始化_单个位图(m三维.fg交换链().Get(), 1);
	m画图形 = m二维.fc画图形();
	m画图形->fs颜色(数学::S颜色::c灰);
	m画文本 = m二维.fc画文本();
	m画文本->fs颜色(数学::S颜色::c白);
	m画文本->fs区域(数学::S向量2::c零);
	auto &v文本工厂 = m二维.fg文本工厂();
	二维::S文本格式参数 v参数;
	v参数.fs字号(48);
	v参数.fs水平对齐(二维::E文本水平对齐::e中);
	v参数.fs垂直对齐(二维::E文本垂直对齐::e中);
	auto v文本格式 = v文本工厂.fc文本格式(v参数);
	m画文本->fs格式(v文本格式.Get());
}
void C图形::f销毁() {
	m着色器v.Reset();
	m着色器p.Reset();
	m三维.f销毁();
}
void C图形::f计算() {

}
void C图形::f更新() {

}
void C图形::f显示() {
	auto &v渲染控制 = m三维.fg渲染控制();
	v渲染控制.f清屏();
	v渲染控制.f绘制(3);
	m二维.f开始();
	m画图形->f填充圆形(数学::S圆形(数学::S向量2::c零, 100));
	m画文本->f绘制文本(L"啊啊啊啊啊啊啊");
	m二维.f结束();
	v渲染控制.f显示();
}