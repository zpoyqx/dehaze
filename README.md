# dehaze
A dehaze method based on CAP, guidedfilter and quadtree

## Preface
The Matlab code for this project came from one of my seniors, and I mainly just modified it to Python and C++ code.

## Instructions
Under the `Images` folder are some fogged photos.

Under the `Results` file are the results after defogging.

In the `Python` folder, there is a code based on dark channel dehaze.

Note that the path inside the code needs to be modified by yourself！

## 2022-09-10补充信息

- 团队成员信息：顾振乾、欧阳钦翔(我)、漆乐然、周洋、曾鹏宇
- 上传了竞赛的完整代码
  - `Dehaze_Code`下包含PYNQ开发板的Python测试文件
  - `HLS`文件夹下的两个Vitis HLS工程用于生成两个IP核
  - `Vivado`文件夹下的Vivado工程使用上述两个IP核生成bit流
  - `Result`文件夹下为生成的bit流，该文件可以PYNQ端被调用
> 可找范赐恩老师求证
