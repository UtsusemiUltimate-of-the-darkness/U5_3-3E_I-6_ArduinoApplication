// 演習課題1: "b"を押すとLEDが点滅するスケッチの作成(回数，速度は任意)

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

    pinMode ( LED, OUTPUT );  // ピンのモード設定

    Serial.begin ( 9600 );    // シリアル通信の初期化
}

int count = 0;  // ボタンが押された回数

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．送信した文字によりLEDの点滅やその時間を変更
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    int inputChar = Serial.read ();  // シリアルモニタからの入力を読み取り

    // バッファのデータサイズが-1でない場合
    if ( inputChar != -1 ) {

        // 入力された文字によりLEDの点灯を切り替え
        switch ( inputChar ) {

            // "b"が入力された場合，LED点滅
            case 'B':
            case 'b':
                count++;                           // count+1
                Serial.println ( "LED: flash" );   // 表示(最後の文字の後に改行)

                // countの回数だけ点滅
                for ( int i = 0; i < count; i++ ) {
                    digitalWrite ( LED, HIGH );    // LED点灯
                    delay ( 300 );                 // 遅延[ms]
                    digitalWrite ( LED, LOW );     // LED消灯
                    delay ( 200 );                 // 遅延[ms]
                }
                break;                             // Switch文終了

            // "r"が入力された場合，カウントリセット
            case 'R':
            case 'r':
                Serial.println ( "countReset" );   // 表示(最後の文字の後に改行)
                digitalWrite ( LED, HIGH );
                delay ( 800 );
                digitalWrite ( LED, LOW );
                count = 0;                         // カウントリセット
                break;                             // Switch文終了

            // 上記以外
            default:
                Serial.println ( "not command" );  // 表示
                break;  // Switch文終了
        }
    }
}
