//=============================================-
//プレイヤーの処理
//=============================================
#include "main.h"
#include "manager.h"
#include "Renderer.h"
#include "player.h"
#include "keyboard.h"
#include "game.h"
#include "fade.h"
#include "XInput.h"
#include "sound.h"
#include "keyboard.h"
#include "effect.h"
#include "Polygon.h"
#include "Particle.h"
#include "directinput.h"
//------------------------------------
//マクロ定義
//------------------------------------
#define MAX_DELAY_TIME (30)
#define MAX_MAGIC_SHOT_TIME (2.0)
#define MAX_PLAYER_JUMP (1)//最大のジャンプ数
#define MAX_PLAYER_PARTS (16)
#define PLAYER_SIZE (20.0)
#define SWORDEFFECT_LONG (16)
#define PLAYER_RANGE (700.0)		//プレイヤーと敵の近さを図る範囲
#define PLAYER_ROCKON_SIZE (5.0)	//ロックオン画像のサイズ
#define PLAYER_POWER (5)			//攻撃力
#define PLAYER_HIT_MAXTIME (50)		//無敵判定の時間
#define PLAYER_DODGE_TIME (20.0f)		//回避の時間
#define PLAYER_DODGE_SPEED (12.0f)		//回避の速度
#define PLAYER_ATTACK_SPEED (15.0f)		//攻撃の移動速度
#define PLAYER_ADDCP (7)		//増加するCP

//--------------------------
//コンストラクト
//--------------------------
CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	memset(m_pMotion, NULL, sizeof(m_pMotion));
	memset(m_pModel, NULL, sizeof(m_pModel));
	memset(m_pSwordEffect, NULL, sizeof(m_pSwordEffect));
	m_fMagicShotDelayMax = MAX_MAGIC_SHOT_TIME;
	m_bAttack = false;
	m_bAttackNext = true;
	m_nMaxDelatTime = MAX_DELAY_TIME;
	m_bDelay = false;
	m_Magic.m_bRetryMagic = false;
	m_pRockOnPolygon = nullptr;
	m_nCommandType = 0;
	m_nMagicCommandType = 0;
	m_bDraw = true;
	m_bHit = false;
	m_bHitStop = false;
	m_State = STATE_NOWN;
	m_bDeth = false;
	m_bLockOn = false;
	m_bDodge = false;
	m_bBeginDodge = false;
	m_bEndDodge = false;
	m_fDodgeAddSpeed = 1.0f;
	m_fDodgeTimer = 0.0f;
	m_fDodgerot = 0.0f;
}
//--------------------------
//デストラクト
//----------------------------
CPlayer::~CPlayer()
{

}
//----------------------------------------------
//インスタンス生成
//----------------------------------------------
CPlayer *CPlayer::Create()
{
	CPlayer *pPlayer = NULL;
	pPlayer = new CPlayer;
	pPlayer->Init();
	return pPlayer;
}
//---------------------------------------------
//初期化
//---------------------------------------------
HRESULT CPlayer::Init()
{
	return S_OK;
}
///-------------------------------------------
//破棄
//------------------------------------------
void CPlayer::Uninit()
{
	Release();
}
//-------------------------------------------
//更新
//-------------------------------------------
void CPlayer::Update()
{
	CXInput *pGamePad = CManager::GetXInput();
	CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();
	if (m_bDeth == false)
	{
		//プレイヤーの移動処理
	}
}
//-------------------------------------------
//描画処理
//-------------------------------------------
void CPlayer::Draw()
{


	//前回の位置情報の保存
	m_lastpos = m_pos;

}
void CPlayer::Drawtext()
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char str[3000];
	int nNum = 0;

	nNum = sprintf(&str[0], "\n\n 壁情報 \n");

	nNum += sprintf(&str[nNum], " [modelPos] X%.2f,Y%.2f,Z%.2f \n", m_pos.x, m_pos.y, m_pos.z);
	nNum += sprintf(&str[nNum], " [modelPos] X%.2f,Y%.2f,Z%.2f \n", m_lastpos.x, m_lastpos.y, m_lastpos.z);

	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// テキスト描画
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}


