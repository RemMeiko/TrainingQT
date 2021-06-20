# TrainingQT

![功能界面](https://mikasae.github.io/Mikasa/other/QT-ico.png)

* 使用zigbee作为硬件，QT作为软件设计的一套智能温湿度检测装置，该仓库存放的是QT软件设计的代码和其他一些如数据库，API等设置和配置
* 界面包括两个：PC端和GEC6818板子两个版本

* 界面功能
  * 注册：
    * 头像采用像素点压缩
    * 头像上传值sm.ms图床
    * 随机验证码
    * 采用写入本地配置实现记住密码，
  * 登陆
    * 通过API匹配数据库确认身份
  * 功能界面
    * 灯光和窗户的开关检测
    * 对数据库中温湿度进行数据可视化(柱形图和折线图分析)
    * 显示最近的温湿度和烟雾传感器数据

[登陆演示动画](https://mikasae.github.io/Mikasa/other/QT_login.gif)

[注册演示动画](https://mikasae.github.io/Mikasa/other/QT_reg.gif)

* 功能界面

> ![功能界面](https://mikasae.github.io/Mikasa/other/QT-Feature1.jpg)
>
> ![功能界面](https://mikasae.github.io/Mikasa/other/QT-Feature2.jpg)
>
> ![功能界面](https://mikasae.github.io/Mikasa/other/QT-Feature3.jpg)
>
> ![功能界面](https://mikasae.github.io/Mikasa/other/QT-Feature4.jpg)

> 整个程序中还存在许多问题，仅限参考，暂时没时间去修改
>
> * 比如采用的是绝对路径，因此使用时尽量放在在D盘，出错时修改一下代码中的路径
> * sm.ms图床那边图片有时不稳定，会出现加载问题
> * .......有问题可联系仓库管理者(可以根据分支去搜索)

