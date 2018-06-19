// アナログ値の入力: 可変抵抗を使用し，抵抗値が変わるとA/D変換値も変化することを確認

// defineはコンパイル時にマクロ変換される
#define VR 0   // 可変抵抗接続ピン

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
 * 処理: 無限ループ．A/D変換値を表示
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    Serial.println ( analogRead (VR) );  // A/D変換値を表示
    delay ( 1000 );                      // 遅延[ms]
}
