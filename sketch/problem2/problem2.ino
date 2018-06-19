// 演習課題2: 3色LEDを入力した文字に対応して各色光らせる

// defineはコンパイル時にマクロ変換される
// LED接続ピン
#define LED_R 8   // 3色LEDredピン
#define LED_G 9   // 3色LEDgreenピン
#define LED_B 10  // 3色LEDblauピン

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 * 返り値: なし
 */
void setup () {
    // put your setup code here, to run once:

    // 各ピン出力モード設定
    for ( int i = 8; i < 11; i++ ) {
        pinMode ( i, OUTPUT );  // 出力に設定
    }

    Serial.begin ( 9600 );      // シリアル通信の初期化
}

// LED点灯フラグ
int flagR = 0;  // LEDred点灯フラグ
int flagG = 0;  // LEDgreen点灯フラグ
int flagB = 0;  // LEDblau点灯フラグ

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．入力された文字に対応したLEDの色を点灯，消灯させる
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    int inputChar = Serial.read ();  // シリアルモニタからの入力を読み取り

    // バッファのデータサイズが-1でない場合
    if ( inputChar != -1 ) {

        // 入力された文字を判定
        switch ( inputChar ) {

            // "r"が入力された場合
            case 'R':
            case 'r':

                // LEDが点灯しているか
                if ( flagR ) {
                    Serial.println ( "Red: OFF" );    // 表示(最後の文字の後に改行)
                    digitalWrite ( LED_R, LOW );      // LED消灯
                    flagR = 0;                        // 点灯フラグを下ろす
                } else {
                    Serial.println ( "Red: ON" );     // 表示(最後の文字の後に改行)
                    digitalWrite ( LED_R, HIGH );     // LED点灯
                    flagR = 1;                        // 点灯フラグを立てる
                }
                break;                                // Switch文終了

            // "g"が入力された場合
            case 'G':
            case 'g':

                // LEDが点灯しているか
                if ( flagG ) {
                    Serial.println ( "Green: OFF" );  // 表示(最後の文字の後に改行)
                    digitalWrite ( LED_G, LOW );      // LED消灯
                    flagG = 0;                        // 点灯フラグを下ろす
                } else {
                    Serial.println ( "Green: ON" );   // 表示(最後の文字の後に改行)
                    digitalWrite ( LED_G, HIGH );     // LED点灯
                    flagG = 1;                        // 点灯フラグを立てる
                }
                break;                                // Switch文終了

            // "b"が入力された場合
            case 'B':
            case 'b':

                // LEDが点灯しているか
                if ( flagB ) {
                    Serial.println ( "Blau: OFF" );   // 表示(最後の文字の後に改行)
                    digitalWrite ( LED_B, LOW );      // LED消灯
                    flagB = 0;                        // 点灯フラグを下ろす
                } else {
                    Serial.println ( "Blau: ON" );    // 表示(最後の文字の後に改行)
                    digitalWrite ( LED_B, HIGH );     // LED点灯
                    flagB = 1;                        // 点灯フラグを立てる
                }
                break;                                // Switch文終了

            // 上記以外
            default:
                // 表示
                Serial.println ( "not command" );
                break;  // Switch文終了
        }
    }
}
