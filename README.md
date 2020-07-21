# LowWeightCipher(Serpenters)

パイコネ変換：https://ja.wikipedia.org/wiki/%E3%83%91%E3%82%A4%E3%81%93%E3%81%AD%E5%A4%89%E6%8F%9B

20200721

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

現状がどうなっているのかよく把握できてないので、漠然としたイメージしかないのですが内部がランダム置換とSboxを使っていて、特に左右を分けることなくバイト単位で混ぜ合わせているという感じです。
今のままだと、単に秘密鍵から乱数を生成して、それをサブキーにしている感じなので、ブロック暗号というよりストリーム暗号になってる感じです。
つまりサブキーの生成をパイコネ変換を使って生成しているという感じでしょうか。
安全性はまだ不確定ですが、実質ストリーム暗号っぽいですね。
そうなるともうストリーム暗号としては遅すぎるのでなんとかブロック暗号の体裁を意識して作り直すつもりです。
