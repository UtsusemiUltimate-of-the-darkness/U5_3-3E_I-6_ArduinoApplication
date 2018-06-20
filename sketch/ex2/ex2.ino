// 例題2: PWMの復習

// defineはコンパイル時にマクロ変換される
#define LED 12  // LED接続ピン
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
    pinMode ( LED, OUTPUT );

    Serial.begin ( 9600 );
}


/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．CdSの抵抗値によってLEDが点滅する速さを変える
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    int val = analogRead ( CdS );  // A/D変換値
    Serial.print ( "val: ");
    Serial.println ( val );

    digitalWrite ( LED, HIGH );   // LED点灯
    delay ( val );                // A/D変換値[ms]遅延
    digitalWrite ( LED, LOW );    // LED消灯
    delay ( val );                // A/D変換値[ms]遅延
}
