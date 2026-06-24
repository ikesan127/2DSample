#include "TitleMenuWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "BattleWidget.h"
#include "Kismet/KismetSystemLibrary.h"

/** 
 * タイトル画面向けC++ファイル
 */

void UTitleMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (StartButton){
        StartButton->OnClicked.AddDynamic(this, &UTitleMenuWidget::OnStartButtonClicked);
    }
    if (EndButton){
        EndButton->OnClicked.AddDynamic(this, &UTitleMenuWidget::OnEndButtonClicked);
    }
}

/** スタートボタン押下時 */
void UTitleMenuWidget::OnStartButtonClicked(){
    if (BattleWidgetInstance){
        BattleWidgetInstance->AddToViewport(1000);
        return;
    }
    if (BattleWidget){
        BattleWidgetInstance = CreateWidget<UBattleWidget>(GetWorld(), BattleWidget);
        if (BattleWidgetInstance){
            BattleWidgetInstance->AddToViewport(1000);
        }
    }
}

/** 終了ボタン押下時 */
void UTitleMenuWidget::OnEndButtonClicked(){
    UKismetSystemLibrary::QuitGame(
        GetWorld(),
        GetOwningPlayer(),
        EQuitPreference::Quit,
        false
    );
}
