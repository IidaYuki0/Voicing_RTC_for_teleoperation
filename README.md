# Voicing_RTC_for_teleoperation
遠隔操作ロボット用の音声発話RTCです

## コンポーネント概要
　移動ロボットの操縦量情報より，音声発話を行うコンポーネントを開発した．当コンポーネントはゲームパッド等の遠隔操作デバイスの入力情報より，コンポーネント内部でロボットの進行方向の場合分けを行い，移動情報に応じた音声ファイルを読み込むことで発話を行う．

## 開発環境
- OS：Windows 10 64bit
- RTミドルウェア：OpenRTM-aist 1.1.2
- Java環境：Java SE Development Kit 7u79 32bit
- 開発環境：Visual Studio 2015 (VC14)
- Phytonバージョン：Phyton 2.7.9
- CMake：CMake-3.5.2
- Eclipse：Eclipse SDK Version: Luna SR2 (4.4.2)
- 使用言語：C++

## 使用機器
- 株式会社イクシス社製　iWs09 移動ロボット（対向2輪型移動ロボット）
（商品リンク：https://www.ixs.co.jp/product/183）
- Logicool Gamepad F310
（商品リンク：https://gaming.logicool.co.jp/ja-jp/products/gamepads/f310-gamepad.html）
- HP ProBook 650 G5（操縦者用PC）
（商品リンク：https://jp.ext.hp.com/notebooks/business/probook_650_g5）
- 東芝dynabook RZ63/A（ロボット側PC）
（商品リンク：https://dynabook.com/direct/pc/catalog/2016-fall-winter/rz63a/spec.html）

## 既存のコンポーネント

###操縦者側コンポーネント
- GamePad_ver2: ゲームパッドの操作量をTimedVelocity2D型で出力するコンポーネント．DXライブラリを用いる．
- ControllerClient: ゲームパッドの操縦量をサーバに送信し，RSNP通信を行うためのコンポーネント．

###ロボット側コンポーネント
-RobotClient_ver2: サーバに送られた操縦量を受取るためのコンポーネント．TimedVelocity2D型を出力する．
-RTC_iWs09: 今回使用する移動ロボットであるiWs09を制御するためのコンポーネント．TimedVelocity2D型を受信する．
