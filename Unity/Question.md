# Question

## 1. fbx文件导入unity中没有贴图
A: 需要框选fbx文件以及 fbm贴图一起导入到unity中，若仍无贴图，点击fbx在Inspector面板中选择Materials中新增Textures和Materials文件夹

## 2. 导入资源包后着色器丢失
A: 使用unity自动升级材质，若没有效果需要手动修改渲染为当前渲染线程，比如HDR渲染下 将shader修改为 HDR/Lit,并手动贴图