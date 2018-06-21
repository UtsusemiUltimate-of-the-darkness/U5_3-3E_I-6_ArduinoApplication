// 演習課題3: 圧電スピーカーを使用して2つの音が交互になるサイレンの作成(周波数，時間は任意)

// defineはコンパイル時にマクロ変換される
#define BZ 9  // 圧電スピーカー接続ピン

// 救急車サイレン周波数
#define Pii 960  // ぴー[Hz]
#define Poo 770  // ぽー[Hz]

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 * 返り値: なし
 */
void setup () {
    // put your setup code here, to run once:

    pinMode ( BZ, OUTPUT );                       // 圧電スピーカー接続ピン
    Serial.begin ( 9600 );                        // シリアル通信の初期化

    // 再生内容を表示
    Serial.println ( "救急車のサイレン" );
    Serial.println ( "pii: 960Hz, poo: 770Hz" );
}

int time_ms = 600;  // 音を鳴らす時間[ms]

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．任意の周波数で音を交互に鳴らしサイレンを鳴らす
 * 返り値: なし
 */
void loop () {
    // put your main code here, to run repeatedly:
    //tone関数は3, 11番ピンの出力を妨げる

    // サイレン鳴らす
    tone ( BZ, Pii, time_ms );  // 音再生
    delay ( time_ms );          // 再生が終わるまで待機
    tone ( BZ, Poo, time_ms );  // 音再生
    delay( time_ms );           // 再生が終わるまで待機
}
