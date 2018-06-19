// 演習問題追加例題5: サーボモータの利用

#include <Servo.h>  // サーボモータ用ライブラリ

// defineはコンパイル時にマクロ変換される
#define SERVO 9  // サーボモータ接続ピン
Servo servo1;    // よくわからん．テキストコメント書けー

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 * 返り値: なし
 */
void setup () {
    // put your setup code here, to run once:

    Serial.begin ( 9600 );    // シリアル通信の初期化
    servo1.attach ( SERVO );  // サーボモータを接続したピンを使用
}

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．サーボモーターの動作確認
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    servo1.write ( 30 );   // サーボモーター30度方向に回転[deg]
    delay ( 2000 );        // 遅延[ms]
    servo1.write ( 150 );  // サーボモーター150度方向に回転[deg]
    delay ( 2000 );        // 遅延[ms]
}
