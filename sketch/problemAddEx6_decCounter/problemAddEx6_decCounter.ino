/**
 * 演習問題追加例題6-2: LCDを利用し10進カウンタの作成
 */

#include <LiquidCrystal.h>  // LCD用ライブラリ

//LCDモジュールの配線(rs, rw, enable, d4, d5, d6, d7)
LiquidCrystal lcd = LiquidCrystal ( 12, 11, 10, 5, 4, 3, 2 );

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 * 返り値: なし
 */
void setup () {
    // put your setup code here, to run once:

    Serial.begin ( 9600 );       // シリアル通信の初期化

    // LCDの設定
    lcd.begin ( 16, 2 );         // LCDの行数, 列数の設定
    lcd.clear ();                // LCDの文字を削除
    lcd.setCursor ( 0, 0 );      // LCDのカーソルを(0,0)に設定
    lcd.print ( "10 Counter" );  // LCDに表示
}

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．作成した文字列をLCDに表示する
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    char outStr[16];                   // 文字列を格納する

    // 文字列の作成と表示
    for ( int x = 0; x < 10; x++ ) {
        sprintf ( outStr, "%2d", x );  // 表示する文字列の作成
        lcd.setCursor ( 0, 1 );        // カーソルを2行目に移動
        lcd.print ( outStr );          // 作成した文字列を表示
        delay ( 1000 );                // 遅延[ms]
    }
}
