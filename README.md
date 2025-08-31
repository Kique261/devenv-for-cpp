# C++ 开发环境配置

这个仓库包含了 C++ 项目的 VS Code 开发环境配置文件，用于快速设置新项目的开发环境。

## 目录结构

```
.
├── .vscode/                 # VS Code 配置文件
│   ├── .clang-tidy          # clang-tidy 代码分析配置
│   ├── c_cpp_properties.json # C/C++ 扩展配置
│   ├── compile_commands.json # 编译命令数据库
│   ├── launch.json          # 调试配置
│   ├── settings.json        # VS Code 设置
│   └── tasks.json           # 构建任务配置
├── bin/                     # 编译输出目录
├── src/                     # 源代码目录
│   └── main.cpp             # 主程序
├── in                       # 输入文件 (用于测试)
└── out                      # 输出文件 (用于测试)
```

## 功能

- 使用 Clang++ 编译器
- LLDB 和 GDB 调试支持
- 代码格式化
- Clang-Tidy 代码分析
- Code Runner 支持
- 优化的任务和调试配置

## 使用方法

1. 克隆此仓库到新项目
2. 根据需要修改 `.vscode` 目录中的配置文件
3. 在 `src` 目录下开发代码
4. 使用 VS Code 的任务系统、Code Runner 或调试器运行程序

## 依赖项

- VS Code
- C/C++ 扩展
- LLDB 扩展 (可选)
- Code Runner 扩展 (可选)
- MSYS2/MinGW64 环境 (Windows)，包含：
  - Clang++ 编译器
  - LLDB/GDB 调试器
  - Clang-Tidy 代码分析工具
