// 温度センサの利用: アナログ温度センサ(LM35)で温度を測定する

// defineはコンパイル時にマクロ変換される
#define LM35 1  // アナログ温度センサ接続ピン

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 * 返り値: なし
 */
void setup () {
    // put your setup code here, to run once:

    Serial.begin ( 9600 );   // シリアル通信の初期化
}

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．温度センサの出力を読み取り，温度を表示
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    Serial.println ( analogRead (LM35) * 0.48 );  // A/D変換値から温度に直して表示
    delay ( 1000 );                               // 遅延[ms]
}
