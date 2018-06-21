// 演習課題7: CdS，ブザー使用．明るさに応じてブザーを鳴らす

// defineはコンパイル時にマクロ変換される
#define CdS 0  // CdSセル接続ピン
#define BZ 9   // ブザー接続ピン

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 * 返り値: なし
 */
void setup () {
    // put your setup code here, to run once:

    Serial.begin ( 9600 );  // シリアル通信の初期化
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
    int f = ain * 2;               // 周波数[Hz]

    // 表示
    Serial.print ( "ain: " );
    Serial.println ( ain );
    Serial.print ( "f: " );
    Serial.println ( f );
    Serial.println ( "" );         // 見やすさのために1行開ける

    // 一定以上の明るさの場合
    if ( 350 < ain && ain < 1000 ) {

        noTone ( BZ );             // tone関数が複数回実行されるのを防ぐため，音止める
        tone ( BZ, f );            // 音鳴らす

    } else {

        noTone ( BZ );             // 音消す
    }

    delay ( 200 );                 // 遅延[ms]
}
