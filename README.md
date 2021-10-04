# M5Stack_MtgBord

## これはなに？
リモートワーク時などで、MTGや電話中の状態の時、部屋に入ってほしくないという意思表示を簡単に行うことができるドアボードです。

## 使い方
1. このリポジトリをgit cloneする
    ```
    https://github.com/ShioriPeace/M5Stack_MTGBord.git
    ```
2. Serial_MtgBord.inoに、WiFiを設定する
    
    UDP通信によって動かすので、普段自宅等で利用しているWifiをここで設定します。
https://github.com/ShioriPeace/M5Stack_MTGBord/blob/faf67875f34748607c8df91148b0ca7ee3b57209/Serial_MtgBord/Serial_MtgBord.ino#L16

3. 送信するPythonのコードを起動する
    ここで、pythonと指定してしまうと、うまく起動しないので、`python3` を指定してください

    ```sh
    $ python3 udpMsg.py
    ```

    以下のように、Pythonが起動したら、M5Stackに送信する準備は完了です。
    ```sh
    3.9.6 (default, Jun 29 2021, 05:25:02) 
    [Clang 12.0.5 (clang-1205.0.22.9)]
    > 
    ```
4. M5Stackに、情報を送信する
    
    ×を表示したい時 : `m` を送信する

    ○を表示したい時 : `m` 以外の文字を送信する
    
    現在送信時に、何かを返すような実装はしていないため、実際に使うと以下のような感じとなります。

    ```
    3.9.6 (default, Jun 29 2021, 05:25:02) 
    [Clang 12.0.5 (clang-1205.0.22.9)]
    > m
    > k
    > m
    > a
    ```

    送信した文字の通り、実際にM5Stackの表示が変われば、成功です。

    ## 作者
    [@shiori_peace](https://twitter.com/shiori_peace)