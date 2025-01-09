# Git Commit 相关规范
- type: 提交的类型（通常是动词），例如：
  - feat：新特性（功能）
  - fix：修复 Bug
  - docs：文档相关
  - style：格式修改（不影响代码逻辑的修改，如代码缩进、空格、注释等）
  - refactor：重构（既不修复 bug，也不添加新功能的代码更改）
  - test：添加或修改测试
  - chore：其他杂项更新，如构建流程、依赖管理等
  - build：构建系统或外部依赖的修改
  - ci：CI 配置文件或脚本的修改
  - perf：性能优化
- scope：可选字段，用来描述提交的模块、组件或相关功能区域。
- message：简短的描述提交内容。

例:
```scss
feat(auth): add login functionality
fix(button): correct color for hover state
docs(readme): update API usage example
refactor(api): simplify response handling
chore(deps): upgrade lodash version
```