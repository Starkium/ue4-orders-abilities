 #pragma once

 #include "CoreMinimal.h"

 #include "GameFramework/HUD.h"

 #include "RTSHUD.generated.h"


 /**
 * HUD with RTS features, such as showing a selection frame.
 */
 UCLASS()
 class ORDERSABILITIES_API ARTSHUD : public AHUD
 {
 	GENERATED_BODY()

 public:
 	/** Whether to always show all health bars. You may expose this in your own Options window: Some professional players might want this for perfect micro-management. */
 	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS|Health Bars")
 	bool bAlwaysShowHealthBars;

 	/** Whether to show health bars for hovered units. */
 	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS|Health Bars")
 	bool bShowHoverHealthBars = true;

 	/** Whether to show health bars for selected units. */
 	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS|Health Bars")
 	bool bShowSelectionHealthBars = true;

 	/** Whether to show health bars while the respective hotkey is pressed. */
 	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS|Health Bars")
 	bool bShowHotkeyHealthBars = true;

     /** Whether to show floating combat texts above actors. */
     UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS|Floating Combat Texts")
     bool bShowFloatingCombatTexts = true;

     /** How many pixels the floating combat text should rise, per second. */
     UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS|Floating Combat Texts")
     float FloatingCombatTextSpeed = 20.0f;

     /** Whether to automatically adjust the alpha value of the color of floating combat texts depending on their elapsed lifetime. */
     UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS|Floating Combat Texts")
     bool bFadeOutFloatingCombatTexts = true;


 	virtual void DrawHUD() override;

     /** Event for drawaing a floating combat text. */
     virtual void NotifyDrawFloatingCombatText(
         AActor* Actor,
         const FString& Text,
         const FLinearColor& Color,
         float Scale,
         float Lifetime,
         float RemainingLifetime,
         float LifetimePercentage,
         float SuggestedTextLeft,
         float SuggestedTextTop);

 	/** Event for drawing an effect for the currently hovered actor. */
 	virtual void NotifyDrawHoveredActorEffect(AActor* HoveredActor);

 	/** Event for drawing the health bar for the specified actor. */
 	virtual void NotifyDrawHealthBar(
 		AActor* Actor,
 		float CurrentHealth,
 		float MaximumHealth,
 		float HealthPercentage,
 		float SuggestedHealthBarLeft,
 		float SuggestedHealthBarTop,
 		float SuggestedHealthBarWidth,
 		float SuggestedHealthBarHeight);

 	/** Event for drawing the selection frame because the mouse is being dragged. */
 	virtual void NotifyDrawSelectionFrame(float ScreenX, float ScreenY, float Width, float Height);

 	/** Event for drawing the construction progress bar for the specified unit. */
 	UFUNCTION(BlueprintImplementableEvent, Category = "RTS", meta = (DisplayName = "DrawConstructionProgressBar"))
 	void ReceiveDrawConstructionProgressBar(
 		AActor* Actor,
 		float ConstructionTime,
 		float RemainingConstructionTime,
 		float ProgressPercentage,
 		float SuggestedProgressBarLeft,
 		float SuggestedProgressBarTop,
 		float SuggestedProgressBarWidth,
 		float SuggestedProgressBarHeight);

     /** Event for drawaing a floating combat text. */
     UFUNCTION(BlueprintImplementableEvent, Category = "RTS", meta = (DisplayName = "DrawFloatingCombatText"))
     void ReceiveDrawFloatingCombatText(
         AActor* Actor,
         const FString& Text,
         const FLinearColor& Color,
         float Scale,
         float Lifetime,
         float RemainingLifetime,
         float LifetimePercentage,
         float SuggestedTextLeft,
         float SuggestedTextTop);

 	/** Event for drawing an effect for the currently hovered actor. */
 	UFUNCTION(BlueprintImplementableEvent, Category = "RTS", meta = (DisplayName = "DrawHoveredActorEffect"))
 	void ReceiveDrawHoveredActorEffect(AActor* HoveredActor);

 	/** Event for drawing the health bar for the specified actor. */
 	UFUNCTION(BlueprintImplementableEvent, Category = "RTS", meta = (DisplayName = "DrawHealthBar"))
 	void ReceiveDrawHealthBar(
 		AActor* Actor,
 		float CurrentHealth,
 		float MaximumHealth,
 		float HealthPercentage,
 		float SuggestedHealthBarLeft,
 		float SuggestedHealthBarTop,
 		float SuggestedHealthBarWidth,
 		float SuggestedHealthBarHeight);

 	/** Event for drawing the selection frame because the mouse is being dragged. */
 	UFUNCTION(BlueprintImplementableEvent, Category = "RTS", meta = (DisplayName = "DrawSelectionFrame"))
 	void ReceiveDrawSelectionFrame(float ScreenX, float ScreenY, float Width, float Height);


 	UFUNCTION(BlueprintCallable)
 	FVector2D GetActorCenterOnScreen(AActor* Actor) const;

 	UFUNCTION(BlueprintCallable)
 	FVector2D GetActorSizeOnScreen(AActor* Actor) const;

 private:
 	/** Draws the current selection frame if mouse is being dragged. */
 	void DrawSelectionFrame();

     /** Draws floating combat texts. */
     void DrawFloatingCombatTexts();

 	/** Draws unit health bars. */
 	void DrawHealthBars();

 	/** Draws the health bar of the specified actor. */
 	void DrawHealthBar(AActor* Actor);

 	/** Draws a custom HUD effect for the currently hovered actor (e.g. player name). */
 	void DrawHoveredActorEffect();

 	/** Suggests a position and size for drawing a progress bar widget for the specified unit. */
 	void SuggestUnitBarSize(AActor* Actor, float& OutLeft, float& OutTop, float& OutWidth, float& OutHeight) const;
 };
