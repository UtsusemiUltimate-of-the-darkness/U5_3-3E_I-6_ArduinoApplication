// 演習課題7: CdS，ブザー使用．明るさに応じてブザーを鳴らす

// defineはコンパイル時にマクロ変換される
#define CdS 2  // CdSセル接続ピン
#define BZ 9   // ブザー接続ピン

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
 * 処理: 無限ループ．明るさに応じてブザーを鳴らす
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    int ain = analogRead ( CdS );  // A/D変換値

    // 一定以上の明るさの場合
    if ( 50 < ain ) {
        tone ( BZ, ain );          // 音鳴らす
    } else {  // やたら暗い場合
        noTone ( BZ );             // 音消す
    }

    Serial.println ( ain );        // 表示(最後の文字の後改行する)

    delay ( 100 );                 // 遅延[ms]
}
