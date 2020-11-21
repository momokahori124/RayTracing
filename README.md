# miniRT (Ray Tracing)
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

`git clone https://github.com/momokahori124/RayTracing.git && make re && make clean`

`./miniRT review/[---.rt] `

# Feature

<img width="484" alt="スクリーンショット 2020-11-21 16 11 29" src="https://user-images.githubusercontent.com/60100351/99870198-94a8f180-2c14-11eb-95a1-bc784d76292e.png">

<img width="587" alt="スクリーンショット 2020-11-21 16 12 32" src="https://user-images.githubusercontent.com/60100351/99870204-9f638680-2c14-11eb-9ab6-7671a1752916.png">

