// 演習課題例1: シリアル通信

// defineはコンパイル時にマクロ変換される
#define LED 9  // LED接続ピン

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 * 返り値: なし
 */
void setup () {
    // put your setup code here, to run once:

    pinMode ( LED, OUTPUT );  // ピンモード設定
    Serial.begin ( 9600 );    // シリアル通信の初期化
}

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．送信した文字によりLEDの点灯を切り変える
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    int inputChar = Serial.read ();  // シリアルモニタからの入力を読み取り

    // データを受信できた場合
    if ( inputChar != -1 ) {

        // 入力された文字によりLEDの点灯を切り替え
        switch ( inputChar ) {
            // "o"が入力された場合
            case 'O':
            case 'o':
                Serial.println ( "LED: ON" );      // 表示(最後の文字の後に改行)
                digitalWrite ( LED, HIGH );        // LED点灯
                break;                             // Switch文終了

            // "p"が入力された場合
           case 'P':
           case 'p':
                Serial.println ( "LED: OFF" );     // 表示(最後の文字の後に改行)
                digitalWrite ( LED, LOW );         // LED消灯
                break;                             // Switch文終了

            // 上記以外
            default:
                Serial.println ( "not command" );  // 表示
                break;                             // Switch文終了
        }
    }
}
