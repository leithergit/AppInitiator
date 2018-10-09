1.把AppInitiator.exe,msvcr120.dll,msvcp120.dll,Configuration.xml四个文件复制到一个目录中，如C:\AppInitiator
2.编辑Configuration.xml文件，内容如下，
 <?xml version="1.0" encoding="utf-8"?>
<App Path = "D:\Program Files\AS300\Angel\AngelServer.exe" Delay="5000"/>
  其中Path的内容为AS300启动器的完整路径
  Delay为延迟启动的时间，单位为毫秒
3.以管理员身份启动进入命令行，运行AppInitiator.exe /Service命令，创建App Initiator服务
4.在故障转移集群管理器中，新建角色，角色类型为通用服务，选择服务：App Initiator，完成配置。

