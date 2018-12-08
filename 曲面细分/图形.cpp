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
	三维::tp顶点着色器 vs;
	三维::tp外壳着色器 hs;
	三维::tp域着色器 ds;
	三维::tp像素着色器 ps;
	v着色器工厂.f编译并创建顶点着色器(vs, L"着色器.hlsl", "vs", v输入布局, v顶点格式);
	v着色器工厂.f编译并创建外壳着色器(hs, L"着色器.hlsl", "hs");
	v着色器工厂.f编译并创建域着色器(ds, L"着色器.hlsl", "ds");
	v着色器工厂.f编译并创建像素着色器(ps, L"着色器.hlsl", "ps");
	v渲染控制.fs顶点着色器(vs.Get());
	v渲染控制.fs外壳着色器(hs.Get());
	v渲染控制.fs域着色器(ds.Get());
	v渲染控制.fs像素着色器(ps.Get());
	v渲染控制.fs输入布局(v输入布局.Get());
	//顶点
	const 数学::S向量2 va顶点[] = {
		数学::S向量2(-0.5f, 0.5f),
		数学::S向量2(0.5f, 0.5f),
		数学::S向量2(-0.5f, -0.5f),
		数学::S向量2(0.5f, -0.5f),
	};
	三维::tp缓冲 v顶点缓冲;
	v缓冲工厂.f创建缓冲(v顶点缓冲, va顶点, sizeof(va顶点), 三维::E缓冲::e顶点);
	v渲染控制.fs顶点缓冲(v顶点缓冲.Get(), sizeof(数学::S向量2));
	//其它
	v渲染控制.fs图元拓扑(三维::E图元拓扑::e补丁4);
	v渲染控制.fs光栅化(v渲染状态.m光栅化.m线框渲染.Get());
	v渲染控制.fs混合(v渲染状态.m混合.m开启透明.Get());
	v渲染控制.fs深度模板(v渲染状态.m深度模板.m正常深度r.Get());
}
void C图形::f销毁() {
	m三维.f销毁();
}
void C图形::f计算() {

}
void C图形::f更新() {

}
void C图形::f显示() {
	auto &v渲染控制 = m三维.fg渲染控制();
	v渲染控制.f清屏();
	v渲染控制.f绘制(4);
	v渲染控制.f显示();
}