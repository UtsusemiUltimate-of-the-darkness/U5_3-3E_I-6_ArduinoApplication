// 例題3: CdSにかかる電圧によってLEDの明るさ変化

// defineはコンパイル時にマクロ変換される
#define LED 9   // LED接続ピン
#define CdS 0   // CdS接続ピン(アナログ)

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 * 返り値: なし
 */
void setup () {
    // put your setup code here, to run once:

    // ピンのモード設定
    pinMode ( LED, OUTPUT );  // 出力モード

    Serial.begin ( 9600 );    // シリアルモニタ初期化
}

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．CdSにかかる電圧を読み取りLEDの明るさを変える
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    int val = analogRead ( CdS );  // A/D変換値

    // 表示
    Serial.print ( "val: " );      // 改行しない
    Serial.println ( val );        // 改行する

    analogWrite ( LED, val / 4 );  // A/D変換値の大きさに基づいてLED点灯

    delay ( 10 );                  // 遅延[ms]
}
