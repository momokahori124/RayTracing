# Ray Tracing
42tokyoの課題。C言語とminilibxで実装しました。

Ray Tracingとは、CG技法の一つ。
物体やカメラの情報が入ったテキストファイルを読み込んで、
物体を３次元空間に配置し、
それをスクリーンという平面に射影することによって
写真のような画像を取得する。

- minilibx (https://github.com/42Paris/minilibx-linux)

# subject 概要

設定ファイルを読み込むと、物体とカメラの情報を元に画像を生成する。

`./miniRT test.rt `でその画像を表示

`./miniRT test.rt --save `でその画像をbmpファイルに保存する。

# Usage

`git clone https://github.com/momokahori124/RayTracing.git && make re`

`./miniRT <review/---/---.rt> `

# Error management

・ファイルがinvalidな時
（.rtで終わってない時、rtファイルではない時、引数の個数が違う時、ファイルが存在しない時など）

```
./miniRT aaa
./miniRT aaa.rt
./miniRT
./miniRT a a a a
```

・オプションが違う時
```
./miniRT valid_file.rt --ooo
```

・rtファイルがフォーマットに沿ってない時
 
```
・255,255, 
・情報が足りない場合
・ベクトルの大きさが０の時
・途中に変な文字が入っている時
・最後に変な文字が入っている時
```

# Feature


