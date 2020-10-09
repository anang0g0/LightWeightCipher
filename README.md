# LowWeightCipher(Serpenters)

パイコネ変換：https://ja.wikipedia.org/wiki/%E3%83%91%E3%82%A4%E3%81%93%E3%81%AD%E5%A4%89%E6%8F%9B

符号を使った疑似乱数生成；https://www.di.ens.fr/~stern/data/St58.pdf

Hash関数を使ったPRNG：http://ijcee.org/papers/439-JE503.pdf

秘密鍵McEliece暗号？：https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.378.9571&rep=rep1&type=pdf


# 20201009

フルタイムで成果主義にあおられることもなく、好きな研究テーマを好きなだけできるというのは大学の教授より恵まれていると思う。
私は研究以外のすべてのことを犠牲にできる人が本当の研究者だと思っている。
そう、結婚も、恋人も、セックスも。

自分は研究者だなんて到底言えないレベルなので、研究者を馬鹿にしているかのように聞こえるかもしれない。
でも、私のやっていることは生涯学習だといえる。
私はアスペルガーなので、そもそも組織には向いていない。
コミュニケーション能力が低いので、組織に所属してもなじめないのだ。
だからソロで研究している。

生涯学習。それでいい。

普通、研究は研究者が所属する学会で発表するのが当たり前になっている。
でも、例えば毎日こうして研究日記をつけることで、学会に所属してないアマチュアの研究が、学会にとって代わることにはならないだろうか。
そのほうが透明性があることにならないだろうか。
英語が苦手な私は日本語でやるしかないのだが、そういう発表は全部英語で行われているので門前払いされる。

GitHubで毎日リアルタイムに研究の進捗を管理できるなら、GitHubは新しい研究のプラットホームになるのではないか。

そうなれば、研究職のリモートワークも実現できる。
例えば生物学は実験のための設備が必要だが、ＩＴや数学にはそういう縛りが存在しない。

日本には研究者の天国みたいな場所が存在しない。
それが研究を取り巻く現状というか、研究職という職業が、誰にも理解されないアートのような柔軟性がないという事実が、一つの問題だと思う。
研究とアートには関係があると思っている。

暗号のほうもちょっと調べている。Raoが必死に反論している。リードソロモンを使えば安全だとか、一方ではバーストエラー訂正符号を使った暗号の解読法なんかもあったりして、何が正しいのかよくわからない。ちょっと面白そうだからやってみようと始めたところだ。

サウジアラビアの研究者が1997年にMcEliece暗号の秘密鍵バージョンなんて私みたいなことを論文で発表しているし、その論文は既にまとめてこのリポジトリに入っているので、知りたい人は読むようにw。

そして私はスペインの研究者より早く、イランの開発した公開鍵暗号の解読に成功している。（これは後日にでも書きます）
生涯学習で暗号解読って最高の過ごし方だと思う。

最近では処理の軽い暗号がＲＦＩＤなんかで需要があるらしく、私が大学院で研究してた暗号方式もいまだに改良版とかが出てきていてまだしつこくやってる人が私以外にもいるのだと感心した。

セキュリティがそこそこでも、使うシーンによって需要が違う。
論文が発表された1989年、つまり30年前とは自分たちが暮らしている社会のデジタル化は全然比べ物にならなくなっている。
そして2000当時流行していた楕円曲線なんかは見事に時代遅れになり、誰も注目してなかった符号ベースの暗号が脚光を浴びる。
プログラミングをして実験したんだから理解できていたのは確かだ。
私が手っ取り早く公開鍵暗号を秘密鍵バージョンにして使うというのも、エラー訂正の時にシンドロームリストを使いたくなかったからだ。
リストの数が指数関数的に増大するので記録しておくのが不可能だからだ。
ネットで調べていると、最初は考案者のＲａｏも同じことをしていたらしい。
そのうち考えを変えて、能力のない符号に過剰なエラーを混ぜて安全性を保つ方法を考え出したのだろう。
そこでは重みが符号長の半分くらいの訂正不能なエラーを使う。
そうすれば選択平文攻撃も防げると書いてある。
鍵のサイズが250ビットくらいだそうなので、かなりコンパクトな暗号だ。
最小距離が6以下のものを使うと書いてある。
8の倍数で符号化率を上げるなら符号長16で次元が8とかがいいかもしれない。
Ｇｏｌａｙ符号は性能が良すぎる。
でも使えなくもない。
組織符号にすれば12＊12＝144ビットで済む。
テーブルも含めると、ゴーレイは意外と手軽かも。
この場合テーブルサイズがネックになるから何か小さくするか、テーブルを改良するとか代わりの方法を見つけるかできれば発明になるかもしれない。
なんかいい方法ないかなと今日も眠気と戦いながら研究をしている。

幸せだ。

# 20201008:復活の日(パイコネール空軍基地　意味不ｗ)

まだ不完全だけど、20年前のRao-Namの攻撃プログラムが見つかったのでとりあえずうｐ。

部分体部分符号を用いたエラー入り秘密鍵暗号とその実装


# 20201006

・課題その１　Rao-Nam型秘密鍵暗号の安全性の下界を比較してみる。


暗号化鍵が見えなければいいので、鍵サイズも公開鍵バージョンよりずっと小さくなる。

その代わりRao-Nam暗号より鍵がでかい。

そしてシンドロームエラーテーブルも使わない。

この場合、選択平分攻撃は、暗号化鍵をブラックボックスとして、ひたすら平文とそれに対応する暗号文を集める差分攻撃になる。

この時、暗号解読に必要となる平文と暗号文のデータを、すべて集めるのが物理的に不可能な時間とサイズを見積もることで、 この手の秘密鍵暗号の様々なバリエーションに、秘密鍵サイズに応じた、安全性に対する一つの下界を算出することができるだろう。

ここでちょっとはみ出してみると、ハミング重み＝最小距離d-1のエラーを混ぜた時、２つの過剰なd-1重みのエラーベクトルの シンドローム衝突を見つける難しさに基づいてハッシュ関数も作れそうなお感がする。

ハッシュ関数の設計に符号理論の結果を使うほうが、無理に死にかけた秘密鍵暗号を組成するよりまともかもしれないが、 それはまた別の研究テーマになる。


ある秘密鍵暗号の試論

公開パラメータ：n=1024,k=32＊10=320,secret key size 320bit(必要なら+320＊320+10＊1024=112960bit),wt(r)=32(r is random error)

暗号化：

1.input m;

2.output randomization c=(H(r)^m,rH);wt(r)=32

PACEではシンドロームエラーテーブルと暗号化行列の両方が秘密鍵であり、暗号化するときも復号するときも同じ鍵を使う。（多分これは普通）

秘密鍵マックリース暗号では、暗号化にゴッパ多項式から生成されるパリティ検査行列を使い、 秘密鍵にゴッパ多項式と復号アルゴリズムにパターソンアルゴリズムを使う。

エラーテーブルは使わない。

ということは毎回秘密鍵から暗号化行列を生成することになり、カギ生成のオーバーヘッドが問題になる。

なんでこんなことをするかというと、単純に、ナードっぽく1つの平文に対して集めきれないほど大きな暗号文が生成されることを狙っているからだ。

参考文献によると、PACE解読にかかる計算量はO(k^2nN^2)であるが、実はこのN(１つの選択平文に対する、可能な全ての暗号文の数)というのは指数的である。

なのでこのNが途轍もなく大きければ計算できないことになる、というのが私の論文の趣旨であった。
実際エラーテーブルを使ってこのＮを大きくしようとすると、秘密鍵サイズも膨大に増えてしまって改良にならない。

そこで、エラーテーブルを使わないで普通に訂正できる範囲内で暗号化復号化できるようにしようという感じで論文を書いた。 
そしてそのようなパラメータとしてn=8192、k=3328を選んだ。（でかすぎｗ）

このパラメータは正しくないと思うのだが、折角だから修論補完計画としてやってみよう。（予定）

PACEではシンドロームエラーテーブルと暗号化行列の両方が秘密鍵であり、暗号化するときも復号するときも同じ鍵を使う。（多分これは普通）


参考文献によると、PACE解読にかかる計算量はO(k^2nN^2)であるが、実はこのN(１つの選択平文に対する、可能な全ての暗号文の数)というのは指数的である。


なのでこのNが途轍もなく大きければ計算できないことになる、というのが私の論文の趣旨であった。 
実際エラーテーブルを使ってこのＮを大きくしようとすると、秘密鍵サイズも膨大に増えてしまって改良にならない。

＊　PACE：Rao-Nam Scheme　＊

１．秘密鍵：ハミング距離=3であるような簡単な符号、ハミング重みｔ=n/2である幾つかの過剰なエラーパターンzとそのシンドロームとの対応表をシンドローム・エラーテーブルZと呼ぶ。

２．暗号化：

G'=SG

c=(mSG+e)P

３．復号：

c=(mSG+e)P=mSGP+eP

c'=cP=mSG+e

c'H=s

Z(s)=e

a=c'^e=c=mSG

a(SG)^{-1}=m

・選択的平文攻撃にかかる計算量O(k^2nN^2logN),n符号長、ｋ符号の次元、Ｎ平文と暗号文のペアの数。（このＮは実はnに対して指数関数になる）

＊ Ｌｉ－Ｗａｎｇ　scheme ＊（後述）

参考文献：THE RAO-NAM SCHEME IS INSECURE AGAINST A CHOSEN-PLAINTEXT ATTACK

https://link.springer.com/chapter/10.1007%2F3-540-48184-2_41

https://link.springer.com/chapter/10.1007/3-540-48184-2_40


20200815

なんだかだんだん不毛になってきたので、開発を中止してSIDHに移行してます。
当分更新しません。

20200724

寝不足で四日目。
昨日も3時間しか眠れなかった。
とりあえず、動的に置換パターンを生成することはできるようになった。
つまりサブキーを作るための32バイトの秘密鍵がないと、置換パターンもわからないということに。
乱数を賭けると逆変換に失敗する。
置換と換字を同時にやることは難しくはない。
逆変換も順番通りにできる。
ところが置き換えながら同一パターンをXORしないと復元不可能になる。
乱数を使ったりすると、内部でバーナム暗号化してしまい、復元できなくなる。
もし秘密鍵が固定でも、置換のパターンが解らなければ、秘密鍵同様にパターンを決定するのは難しいのではないか？
まだわからないが。

自前の乱数を作ろうとしてあれこれいじっているうちに、どのファイルも動かなくなったのでバージョンダウン。
自作じゃないけどうまく行くファイルに状態を戻した。
置換も秘密鍵に合わせて変えられるようになった。
何だかうんざりしてきたので、当分自作乱数は使わない予定。

サブキーの生成。ちょっと不安だったので調べてみたら、やっぱり0だった！
しかも意味なくバッファをコピーして、コピーされた情報は何も使われない。
こうなったら平文に直接数字をXORして暗号化のときは置き換える前に、復号化するときは後に繰り返しXORしようと思いやったところやっと正解に行き着いた。
コードを読む能力がないのは困る。

20200723

置換パターンを秘密鍵のハッシュ値をシードに暗号学的に安全な疑似乱数を使った乱数で２つの置換パターンを生成し、それを動的置換パターンとして置き換えることにしました。
BBS疑似乱数は遅いし、でかい数を使わないと出来ないので、符号かPKPを使った疑似乱数生成器を自作しないといけなくなりました。
暗号学的に安全な疑似乱数生成器の定義と構成法は、ゴールドライヒのfoundation of Cryptographyに乗っているので調べてみます。
今はscanfを使った体験版ですが、ここ数日中に移行します。

時間が経つに連れ、どんどん脆弱性が明らかになっていく感じがしますｗ。
置換パターンを生成するプログラム(p.c)を公開しました。

ほとんど寝てなくて開発できない。
サブキーを入れるタイミングとサブキーの生成処理を変更した。
生成方法はかなりいい加減です。
なので本当にこれでいいのかは謎。
次回までに調べておきます。

すみません、訂正です。
パイコネじゃありません。
もし平文をカオスで暗号化するなら、カオスはストリーム暗号にしか使えないはずです。
なぜならカオスは非可逆的だからです。
暗号化に直接カオスを利用するような方法があるかも知れないですが、今のところは使ってないです。
カオスを使っているとしたら、マスターキーからサブキーを生成するときに、６４ビットブロックの鍵をシフトしながら自分自身にXORしているところでしょうか？
自分自身にXORすることをパイコネと読んでいるつもりでした。
しかしハッシュ関数にパイコネ変換が適用できても、ブロック暗号にこの方法が直接適用できるわけではなさそうです。

今の所、動的に平文を入れ替えながらSboxで換字するという方法は復号に成功してます。
しかし、置換パターンを動的にするのはSboxの動的生成と比べて本質的ではないかも知れない。
この方法は後日、攻撃方法を適用するに当たって弱点にしかならないことが解るかも知れないです。

解読できる可能性は、置換パターンが固定して公開してあることから想像がつきます。

XOR処理は入力と出力の差分が分ってしまえばサブキーの生成方法が分っているので、秘密鍵を特定することができるはずです。
一つの改良案としては、公開されている置換パターンを、秘密鍵に応じて動的に生成するようなやり方を試すことです。
攻撃を不可能にするためには何が必要かを考えなければなりません。


20200722

間違いに気づいたけど、難なくクリア。
まさか今日中に解決するとは思わなかった。
何も調べないで作った割には良く出来てると思う。
乱数をシーケンシャルに使うと駄目なことが判明。
ということは昨日考えていたようにサブキーがカオスというのは使えないことに。
ということはこの暗号の特徴はこのトランプのシャッフルみたいに動的置換をやっても復号できるというのが特徴なのかも。
同期を取った32バイトの乱数を使って、パッチを当てるようにサブキーとして使う分にはうまく行く。
ちゃんとラウンド内でローテーションできてるし、強いて言えば遅いのが欠点。
サブキーをシフトとかやって処理を軽くすることもできるけど、ひねりが足りないのでつまらない。
どんな落とし穴があるかわからないので、まだ気をつけなければならないが、サブキーを対して考えもせずに導入できたのは嬉しい。
でもただサブキーが使えるようになっただけじゃ楽しくないので、共用体を活用してスピードアップも計ってみた。
測定すると、sage-9.0のソースで11秒。
まあまあの性能。

よくある経験だけどデータが0とかで偶然うまく行っているような場合も有って、今日はそれにハマった。
どこまで正しいか解らなくなった。
全部表示させて確認とか。
部分計算を独立させて動かすと何の問題もないのに、処理している間にデータが消えて全部ゼロになるというバグなんて想像してなかった。
まあ、実装ミスだろうということでバグ取り計画に記録。

全然設計に時間をかけていないので、どの程度駄目なのかは未確定だ。
このままだとAESの128ビット暗号のようにはならず、SHACAL-2 -NESSIEのように256ビットブロックサイズの暗号になりそうだ。
アイデア通りに処理ブロックを32バイトで固定して、そのすべてのバイト全体を繰り返し置換している。
一つのブロックが10回位シャッフルされるのに対して、置換群の位数は1700以上あるのでそんなに簡単には周期が出てこない。
一つのブロックを処理している間は確実に異なる置き換えがなされるはずだ。（間違っているかも知れない）

でも大丈夫だと思うのは、1ビットでも計算が合わないと、出てくるデータがぐちゃぐちゃになっていることからすぐ解る。


出来上がったと思ったらとんでもない勘違いをしていたが、漸くサブキー付きの簡単なSPNのイメージになった。
back2theEggの頃からか違いしていて、ラウンド数を更新するときに必要な関数を一つ飛ばしていたので完全な間違いをしていたことが発覚。
道理で調子が良すぎると思った。
自分で気づくのはなかなか難しいけど、気づかないよりはマシだ。
置換というのは非可換軍なので、一回暗号化してしまうと逆回転させないといけない。
そこで復号キーとして、トータルで何回ラウンドしたかがわかれば逆回転して復号できると思った。
で、ちょっとしたカウンタなんかをつけてみたり。

何だかもう一夜にして出来上がってしまった単純なSPN構造。
でも自分のやりたいことじゃなくて、かなり妥協している。
サブキーは乱数じゃうまく行かないので、単に鍵の配列を入れ替えているだけだし、どうして乱数にするとうまく複合できないのかがわからない。
同じ操作を繰り返しているだけだから、本来は復号できるはずなのだ。
それにラウンド内で配列操作すると計算量が増えるので遅くなる。
これにはなんとか乱数化したような処理を付け足す予定。
つまり同じものが再生できてないということなのだろうが、まだそこまでは確認していない。
とにかく暫定版というべきものが出来たはず。
換字と置換しかしてない。

20200721

処理単位を64バイトから32バイトに変更しました。
速度は余り変わりがありません。

ハッシュの延長でやっていた秘密鍵暗号を独立したリポジトリに移しました。
今後はこちらで開発を勧めます。
ハッシュ関数と秘密鍵暗号を並列で取り組むのでどちらかに偏るかも知れません。
本当なら計算コストが低い（処理が軽い）暗号を作りたいところですが、安全性を考えるとどうしても処理が増えてしまい、簡単な処理ではうまく行きません。
簡単な処理で強い暗号を作るというのはなかなか難しいものです。

微妙に実装が変わっています。
ほとんど変わってませんが、サブキーの生成がより安全になった感じです。

今後1,2週間をかけて、Feistel型とSPN型の可変式実装を行う予定です。
そのためにはきちんと設計し直す必要が有ります。
今のままでも自分のイメージ通りには動いていますが、それを押し通すよりマナーに従ったほうが得だという算段です。

実装完了後、差分攻撃と線形解読法の実装の準備を始めます。
攻撃方法を理解する方が難しいでしょう。
攻撃法の実装には約1か月の時間がかかると思います。

現状がどうなっているのかよく把握できてないので、漠然としたイメージしかないのですが内部がランダム置換とSboxを使っていて、特に左右を分けることなくバイト単位で混ぜ合わせているという感じです。
バッファサイズが2048バイトに対して、処理ブロックが64バイト、そのうち32バイトをF関数に入れるFeistel構造と、64バイト全体に置換をかけるSPN構造の二つの方法を同時に実装します。
今のままだと処理単位が512ビットと多すぎるので、32バイト（あるいは16バイト）に修正する可能性があります。
それはAESの256ビット鍵がどのように鍵より小さなブロックサイズに使われているか調べることでわかるでしょう。
秘密鍵のサイズは256ビット固定です。
これ以上小さな秘密鍵は使わないと思うので。

サブキーのサイズが32バイトとして128ビットブロック暗号にするためには、サブキーの半分だけ使用することで対応できます。
また、サブキーというのは逆算できないといけないものなのか、それとも復元できない方がいいのかはまだ調べてません。
もし復元できないとダメな場合は、サブキー生成にカオスは使えないことになります。
パイコネっていうだけで、カオス決定なのでその点は間違いないでしょう。
今のままだと、単に秘密鍵から乱数を生成して、それをサブキーにしている感じなので、ブロック暗号というよりストリーム暗号になってる感じです。
安全性はまだ不確定ですが、実質ストリーム暗号っぽいですね。
そうなるともうストリーム暗号としては遅すぎるのでなんとかブロック暗号の体裁を意識して作り直すつもりです。

カオスを作るような置換は漸化式であらわすことが出来ます。
置換群には古い歴史と、奥深さがある領域ですが、日本で置換群を専門にやっている人はまずいないといっていいでしょう。
研究者の層の厚さが英語文化圏と日本の差です。
日本ではやっていないような研究も海外ではありますが、日本でしか行われていない研究はまずないはずです。
で、その漸化式ですが、単なる置換ではいいカオスは作れません。
二つの置換群x,yを用意し、xの逆元をx^-1であらわします。
この時、

y_(i+1)=xy_(i)x^-1

という漸化式であらわすことのできる置換ｙだけが乱数を作ることが出来ます。
なぜこの場合だといい乱数が作れるのかはまだ分かっていません。（未解決問題）
