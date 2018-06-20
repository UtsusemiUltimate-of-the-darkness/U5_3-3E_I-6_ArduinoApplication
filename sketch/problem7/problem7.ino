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

int flagTone = 0;  // tone関数実行フラグ

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
    Serial.print ( "ain: " );      // 改行しない
    Serial.println ( ain );        // 改行する
    Serial.print ( "f: " );        // 改行しない
    Serial.println ( f );          // 改行する
    Serial.println ( "" );         // 見やすさのために1行開ける

    // 一定以上の明るさの場合
    if ( 350 < ain && ain < 1000 ) {

        // tone関数が実行されていないか
        if ( !flagTone ) {
            tone ( BZ, f );        // 音鳴らす
            flagTone = 1;          // フラグを立てる
        }
    } else {
        noTone ( BZ );             // 音消す
        flagTone = 0;              // フラグを下ろす
    }

    delay ( 200 );                 // 遅延[ms]
}
