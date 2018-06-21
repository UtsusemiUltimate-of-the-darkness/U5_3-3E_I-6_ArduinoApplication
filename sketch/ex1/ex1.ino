// 例題1: CdSセルを用いて復習

// defineはコンパイル時にマクロ変換される
#define LED 12  // LED接続ピン
#define CdS 7   // CdS接続ピン

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 * 返り値: なし
 */
void setup () {
    // put your setup code here, to run once:

    // 各ピンのモード設定
    pinMode ( LED, OUTPUT );  // 出力に設定
    pinMode ( CdS, INPUT );   // 入力に設定

    Serial.begin ( 9600 );    // シリアルモニタ初期化
}

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．CdSにかかる電圧を読み取りLEDの点灯を切り替える
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    // 表示
    Serial.println ( digitalRead ( CdS ) );

    // CdSのにかかる電圧が2.5V以上であるか
    if ( digitalRead ( CdS ) ) {
        digitalWrite ( LED, HIGH );  // LED点灯
    } else {
        digitalWrite ( LED, LOW );   // LED消灯
    }
    delay ( 100 );
}
