// 距離センサ(測距モジュール)の利用: アナログ距離センサ(測距モジュール, SHARP 2Y0A21)で障害物までの距離を測定

// defineはコンパイル時にマクロ変換される
#define SH_2Y0A21 2  // 測距センサ接続ピン

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

int count = 5;  // 測定回数

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．距離センサからの出力を取得，距離を計算して表示
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:

    int ain = 0;  // A/D変換値

    // 平均A/D変換値を出すため，総和する
    for ( int i = 0; i < count; i++ ) {
        ain += analogRead ( SH_2Y0A21 );
    }
    ain = ain / count;                       // 平均A/D変換値

    float dcm = ( 6787 / ( ain - 3 ) ) - 4;  // 距離[cm]

    // 表示
    Serial.print ( dcm );                    // 開業しない
    Serial.println ( " cm" );                // 開業する

    delay ( 1000 );                          // 遅延
}
