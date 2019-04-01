/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SdkConstants.h"

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace aapt {

static const std::vector<std::pair<uint16_t, size_t>> sAttrIdMap = {
    { 0x021c, 1 },
    { 0x021d, 2 },
    { 0x0269, SDK_CUPCAKE },
    { 0x028d, SDK_DONUT },
    { 0x02ad, SDK_ECLAIR },
    { 0x02b3, SDK_ECLAIR_0_1 },
    { 0x02b5, SDK_ECLAIR_MR1 },
    { 0x02bd, SDK_FROYO },
    { 0x02cb, SDK_GINGERBREAD },
    { 0x0361, SDK_HONEYCOMB },
    { 0x0363, SDK_HONEYCOMB_MR1 },
    { 0x0366, SDK_HONEYCOMB_MR2 },
    { 0x03a6, SDK_ICE_CREAM_SANDWICH },
    { 0x03ae, SDK_JELLY_BEAN },
    { 0x03cc, SDK_JELLY_BEAN_MR1 },
    { 0x03da, SDK_JELLY_BEAN_MR2 },
    { 0x03f1, SDK_KITKAT },
    { 0x03f6, SDK_KITKAT_WATCH },
    { 0x04ce, SDK_LOLLIPOP },
};

static bool lessEntryId(const std::pair<uint16_t, size_t>& p, uint16_t entryId) {
    return p.first < entryId;
}

size_t findAttributeSdkLevel(ResourceId id) {
    if (id.packageId() != 0x01 && id.typeId() != 0x01) {
        return 0;
    }
    auto iter = std::lower_bound(sAttrIdMap.begin(), sAttrIdMap.end(), id.entryId(), lessEntryId);
    if (iter == sAttrIdMap.end()) {
        return SDK_LOLLIPOP_MR1;
    }
    return iter->second;
}

static const std::unordered_map<std::u16string, size_t> sAttrMap = {
    { u"marqueeRepeatLimit", 2 },
    { u"windowNoDisplay", 3 },
    { u"backgroundDimEnabled", 3 },
    { u"inputType", 3 },
    { u"isDefault", 3 },
    { u"windowDisablePreview", 3 },
    { u"privateImeOptions", 3 },
    { u"editorExtras", 3 },
    { u"settingsActivity", 3 },
    { u"fastScrollEnabled", 3 },
    { u"reqTouchScreen", 3 },
    { u"reqKeyboardType", 3 },
    { u"reqHardKeyboard", 3 },
    { u"reqNavigation", 3 },
    { u"windowSoftInputMode", 3 },
    { u"imeFullscreenBackground", 3 },
    { u"noHistory", 3 },
    { u"headerDividersEnabled", 3 },
    { u"footerDividersEnabled", 3 },
    { u"candidatesTextStyleSpans", 3 },
    { u"smoothScrollbar", 3 },
    { u"reqFiveWayNav", 3 },
    { u"keyBackground", 3 },
    { u"keyTextSize", 3 },
    { u"labelTextSize", 3 },
    { u"keyTextColor", 3 },
    { u"keyPreviewLayout", 3 },
    { u"keyPreviewOffset", 3 },
    { u"keyPreviewHeight", 3 },
    { u"verticalCorrection", 3 },
    { u"popupLayout", 3 },
    { u"state_long_pressable", 3 },
    { u"keyWidth", 3 },
    { u"keyHeight", 3 },
    { u"horizontalGap", 3 },
    { u"verticalGap", 3 },
    { u"rowEdgeFlags", 3 },
    { u"codes", 3 },
    { u"popupKeyboard", 3 },
    { u"popupCharacters", 3 },
    { u"keyEdgeFlags", 3 },
    { u"isModifier", 3 },
    { u"isSticky", 3 },
    { u"isRepeatable", 3 },
    { u"iconPreview", 3 },
    { u"keyOutputText", 3 },
    { u"keyLabel", 3 },
    { u"keyIcon", 3 },
    { u"keyboardMode", 3 },
    { u"isScrollContainer", 3 },
    { u"fillEnabled", 3 },
    { u"updatePeriodMillis", 3 },
    { u"initialLayout", 3 },
    { u"voiceSearchMode", 3 },
    { u"voiceLanguageModel", 3 },
    { u"voicePromptText", 3 },
    { u"voiceLanguage", 3 },
    { u"voiceMaxResults", 3 },
    { u"bottomOffset", 3 },
    { u"topOffset", 3 },
    { u"allowSingleTap", 3 },
    { u"handle", 3 },
    { u"content", 3 },
    { u"animateOnClick", 3 },
    { u"configure", 3 },
    { u"hapticFeedbackEnabled", 3 },
    { u"innerRadius", 3 },
    { u"thickness", 3 },
    { u"sharedUserLabel", 3 },
    { u"dropDownWidth", 3 },
    { u"dropDownAnchor", 3 },
    { u"imeOptions", 3 },
    { u"imeActionLabel", 3 },
    { u"imeActionId", 3 },
    { u"imeExtractEnterAnimation", 3 },
    { u"imeExtractExitAnimation", 3 },
    { u"tension", 4 },
    { u"extraTension", 4 },
    { u"anyDensity", 4 },
    { u"searchSuggestThreshold", 4 },
    { u"includeInGlobalSearch", 4 },
    { u"onClick", 4 },
    { u"targetSdkVersion", 4 },
    { u"maxSdkVersion", 4 },
    { u"testOnly", 4 },
    { u"contentDescription", 4 },
    { u"gestureStrokeWidth", 4 },
    { u"gestureColor", 4 },
    { u"uncertainGestureColor", 4 },
    { u"fadeOffset", 4 },
    { u"fadeDuration", 4 },
    { u"gestureStrokeType", 4 },
    { u"gestureStrokeLengthThreshold", 4 },
    { u"gestureStrokeSquarenessThreshold", 4 },
    { u"gestureStrokeAngleThreshold", 4 },
    { u"eventsInterceptionEnabled", 4 },
    { u"fadeEnabled", 4 },
    { u"backupAgent", 4 },
    { u"allowBackup", 4 },
    { u"glEsVersion", 4 },
    { u"queryAfterZeroResults", 4 },
    { u"dropDownHeight", 4 },
    { u"smallScreens", 4 },
    { u"normalScreens", 4 },
    { u"largeScreens", 4 },
    { u"progressBarStyleInverse", 4 },
    { u"progressBarStyleSmallInverse", 4 },
    { u"progressBarStyleLargeInverse", 4 },
    { u"searchSettingsDescription", 4 },
    { u"textColorPrimaryInverseDisableOnly", 4 },
    { u"autoUrlDetect", 4 },
    { u"resizeable", 4 },
    { u"required", 5 },
    { u"accountType", 5 },
    { u"contentAuthority", 5 },
    { u"userVisible", 5 },
    { u"windowShowWallpaper", 5 },
    { u"wallpaperOpenEnterAnimation", 5 },
    { u"wallpaperOpenExitAnimation", 5 },
    { u"wallpaperCloseEnterAnimation", 5 },
    { u"wallpaperCloseExitAnimation", 5 },
    { u"wallpaperIntraOpenEnterAnimation", 5 },
    { u"wallpaperIntraOpenExitAnimation", 5 },
    { u"wallpaperIntraCloseEnterAnimation", 5 },
    { u"wallpaperIntraCloseExitAnimation", 5 },
    { u"supportsUploading", 5 },
    { u"killAfterRestore", 5 },
    { u"restoreNeedsApplication", 5 },
    { u"smallIcon", 5 },
    { u"accountPreferences", 5 },
    { u"textAppearanceSearchResultSubtitle", 5 },
    { u"textAppearanceSearchResultTitle", 5 },
    { u"summaryColumn", 5 },
    { u"detailColumn", 5 },
    { u"detailSocialSummary", 5 },
    { u"thumbnail", 5 },
    { u"detachWallpaper", 5 },
    { u"finishOnCloseSystemDialogs", 5 },
    { u"scrollbarFadeDuration", 5 },
    { u"scrollbarDefaultDelayBeforeFade", 5 },
    { u"fadeScrollbars", 5 },
    { u"colorBackgroundCacheHint", 5 },
    { u"dropDownHorizontalOffset", 5 },
    { u"dropDownVerticalOffset", 5 },
    { u"quickContactBadgeStyleWindowSmall", 6 },
    { u"quickContactBadgeStyleWindowMedium", 6 },
    { u"quickContactBadgeStyleWindowLarge", 6 },
    { u"quickContactBadgeStyleSmallWindowSmall", 6 },
    { u"quickContactBadgeStyleSmallWindowMedium", 6 },
    { u"quickContactBadgeStyleSmallWindowLarge", 6 },
    { u"author", 7 },
    { u"autoStart", 7 },
    { u"expandableListViewWhiteStyle", 8 },
    { u"installLocation", 8 },
    { u"vmSafeMode", 8 },
    { u"webTextViewStyle", 8 },
    { u"restoreAnyVersion", 8 },
    { u"tabStripLeft", 8 },
    { u"tabStripRight", 8 },
    { u"tabStripEnabled", 8 },
    { u"logo", 9 },
    { u"xlargeScreens", 9 },
    { u"immersive", 9 },
    { u"overScrollMode", 9 },
    { u"overScrollHeader", 9 },
    { u"overScrollFooter", 9 },
    { u"filterTouchesWhenObscured", 9 },
    { u"textSelectHandleLeft", 9 },
    { u"textSelectHandleRight", 9 },
    { u"textSelectHandle", 9 },
    { u"textSelectHandleWindowStyle", 9 },
    { u"popupAnimationStyle", 9 },
    { u"screenSize", 9 },
    { u"screenDensity", 9 },
    { u"allContactsName", 11 },
    { u"windowActionBar", 11 },
    { u"actionBarStyle", 11 },
    { u"navigationMode", 11 },
    { u"displayOptions", 11 },
    { u"subtitle", 11 },
    { u"customNavigationLayout", 11 },
    { u"hardwareAccelerated", 11 },
    { u"measureWithLargestChild", 11 },
    { u"animateFirstView", 11 },
    { u"dropDownSpinnerStyle", 11 },
    { u"actionDropDownStyle", 11 },
    { u"actionButtonStyle", 11 },
    { u"showAsAction", 11 },
    { u"previewImage", 11 },
    { u"actionModeBackground", 11 },
    { u"actionModeCloseDrawable", 11 },
    { u"windowActionModeOverlay", 11 },
    { u"valueFrom", 11 },
    { u"valueTo", 11 },
    { u"valueType", 11 },
    { u"propertyName", 11 },
    { u"ordering", 11 },
    { u"fragment", 11 },
    { u"windowActionBarOverlay", 11 },
    { u"fragmentOpenEnterAnimation", 11 },
    { u"fragmentOpenExitAnimation", 11 },
    { u"fragmentCloseEnterAnimation", 11 },
    { u"fragmentCloseExitAnimation", 11 },
    { u"fragmentFadeEnterAnimation", 11 },
    { u"fragmentFadeExitAnimation", 11 },
    { u"actionBarSize", 11 },
    { u"imeSubtypeLocale", 11 },
    { u"imeSubtypeMode", 11 },
    { u"imeSubtypeExtraValue", 11 },
    { u"splitMotionEvents", 11 },
    { u"listChoiceBackgroundIndicator", 11 },
    { u"spinnerMode", 11 },
    { u"animateLayoutChanges", 11 },
    { u"actionBarTabStyle", 11 },
    { u"actionBarTabBarStyle", 11 },
    { u"actionBarTabTextStyle", 11 },
    { u"actionOverflowButtonStyle", 11 },
    { u"actionModeCloseButtonStyle", 11 },
    { u"titleTextStyle", 11 },
    { u"subtitleTextStyle", 11 },
    { u"iconifiedByDefault", 11 },
    { u"actionLayout", 11 },
    { u"actionViewClass", 11 },
    { u"activatedBackgroundIndicator", 11 },
    { u"state_activated", 11 },
    { u"listPopupWindowStyle", 11 },
    { u"popupMenuStyle", 11 },
    { u"textAppearanceLargePopupMenu", 11 },
    { u"textAppearanceSmallPopupMenu", 11 },
    { u"breadCrumbTitle", 11 },
    { u"breadCrumbShortTitle", 11 },
    { u"listDividerAlertDialog", 11 },
    { u"textColorAlertDialogListItem", 11 },
    { u"loopViews", 11 },
    { u"dialogTheme", 11 },
    { u"alertDialogTheme", 11 },
    { u"dividerVertical", 11 },
    { u"homeAsUpIndicator", 11 },
    { u"enterFadeDuration", 11 },
    { u"exitFadeDuration", 11 },
    { u"selectableItemBackground", 11 },
    { u"autoAdvanceViewId", 11 },
    { u"useIntrinsicSizeAsMinimum", 11 },
    { u"actionModeCutDrawable", 11 },
    { u"actionModeCopyDrawable", 11 },
    { u"actionModePasteDrawable", 11 },
    { u"textEditPasteWindowLayout", 11 },
    { u"textEditNoPasteWindowLayout", 11 },
    { u"textIsSelectable", 11 },
    { u"windowEnableSplitTouch", 11 },
    { u"indeterminateProgressStyle", 11 },
    { u"progressBarPadding", 11 },
    { u"animationResolution", 11 },
    { u"state_accelerated", 11 },
    { u"baseline", 11 },
    { u"homeLayout", 11 },
    { u"opacity", 11 },
    { u"alpha", 11 },
    { u"transformPivotX", 11 },
    { u"transformPivotY", 11 },
    { u"translationX", 11 },
    { u"translationY", 11 },
    { u"scaleX", 11 },
    { u"scaleY", 11 },
    { u"rotation", 11 },
    { u"rotationX", 11 },
    { u"rotationY", 11 },
    { u"showDividers", 11 },
    { u"dividerPadding", 11 },
    { u"borderlessButtonStyle", 11 },
    { u"dividerHorizontal", 11 },
    { u"itemPadding", 11 },
    { u"buttonBarStyle", 11 },
    { u"buttonBarButtonStyle", 11 },
    { u"segmentedButtonStyle", 11 },
    { u"staticWallpaperPreview", 11 },
    { u"allowParallelSyncs", 11 },
    { u"isAlwaysSyncable", 11 },
    { u"verticalScrollbarPosition", 11 },
    { u"fastScrollAlwaysVisible", 11 },
    { u"fastScrollThumbDrawable", 11 },
    { u"fastScrollPreviewBackgroundLeft", 11 },
    { u"fastScrollPreviewBackgroundRight", 11 },
    { u"fastScrollTrackDrawable", 11 },
    { u"fastScrollOverlayPosition", 11 },
    { u"customTokens", 11 },
    { u"nextFocusForward", 11 },
    { u"firstDayOfWeek", 11 },
    { u"showWeekNumber", 11 },
    { u"minDate", 11 },
    { u"maxDate", 11 },
    { u"shownWeekCount", 11 },
    { u"selectedWeekBackgroundColor", 11 },
    { u"focusedMonthDateColor", 11 },
    { u"unfocusedMonthDateColor", 11 },
    { u"weekNumberColor", 11 },
    { u"weekSeparatorLineColor", 11 },
    { u"selectedDateVerticalBar", 11 },
    { u"weekDayTextAppearance", 11 },
    { u"dateTextAppearance", 11 },
    { u"solidColor", 11 },
    { u"spinnersShown", 11 },
    { u"calendarViewShown", 11 },
    { u"state_multiline", 11 },
    { u"detailsElementBackground", 11 },
    { u"textColorHighlightInverse", 11 },
    { u"textColorLinkInverse", 11 },
    { u"editTextColor", 11 },
    { u"editTextBackground", 11 },
    { u"horizontalScrollViewStyle", 11 },
    { u"layerType", 11 },
    { u"alertDialogIcon", 11 },
    { u"windowMinWidthMajor", 11 },
    { u"windowMinWidthMinor", 11 },
    { u"queryHint", 11 },
    { u"fastScrollTextColor", 11 },
    { u"largeHeap", 11 },
    { u"windowCloseOnTouchOutside", 11 },
    { u"datePickerStyle", 11 },
    { u"calendarViewStyle", 11 },
    { u"textEditSidePasteWindowLayout", 11 },
    { u"textEditSideNoPasteWindowLayout", 11 },
    { u"actionMenuTextAppearance", 11 },
    { u"actionMenuTextColor", 11 },
    { u"textCursorDrawable", 12 },
    { u"resizeMode", 12 },
    { u"requiresSmallestWidthDp", 12 },
    { u"compatibleWidthLimitDp", 12 },
    { u"largestWidthLimitDp", 12 },
    { u"state_hovered", 13 },
    { u"state_drag_can_accept", 13 },
    { u"state_drag_hovered", 13 },
    { u"stopWithTask", 13 },
    { u"switchTextOn", 13 },
    { u"switchTextOff", 13 },
    { u"switchPreferenceStyle", 13 },
    { u"switchTextAppearance", 13 },
    { u"track", 13 },
    { u"switchMinWidth", 13 },
    { u"switchPadding", 13 },
    { u"thumbTextPadding", 13 },
    { u"textSuggestionsWindowStyle", 13 },
    { u"textEditSuggestionItemLayout", 13 },
    { u"rowCount", 13 },
    { u"rowOrderPreserved", 13 },
    { u"columnCount", 13 },
    { u"columnOrderPreserved", 13 },
    { u"useDefaultMargins", 13 },
    { u"alignmentMode", 13 },
    { u"layout_row", 13 },
    { u"layout_rowSpan", 13 },
    { u"layout_columnSpan", 13 },
    { u"actionModeSelectAllDrawable", 13 },
    { u"isAuxiliary", 13 },
    { u"accessibilityEventTypes", 13 },
    { u"packageNames", 13 },
    { u"accessibilityFeedbackType", 13 },
    { u"notificationTimeout", 13 },
    { u"accessibilityFlags", 13 },
    { u"canRetrieveWindowContent", 13 },
    { u"listPreferredItemHeightLarge", 13 },
    { u"listPreferredItemHeightSmall", 13 },
    { u"actionBarSplitStyle", 13 },
    { u"actionProviderClass", 13 },
    { u"backgroundStacked", 13 },
    { u"backgroundSplit", 13 },
    { u"textAllCaps", 13 },
    { u"colorPressedHighlight", 13 },
    { u"colorLongPressedHighlight", 13 },
    { u"colorFocusedHighlight", 13 },
    { u"colorActivatedHighlight", 13 },
    { u"colorMultiSelectHighlight", 13 },
    { u"drawableStart", 13 },
    { u"drawableEnd", 13 },
    { u"actionModeStyle", 13 },
    { u"minResizeWidth", 13 },
    { u"minResizeHeight", 13 },
    { u"actionBarWidgetTheme", 13 },
    { u"uiOptions", 13 },
    { u"subtypeLocale", 13 },
    { u"subtypeExtraValue", 13 },
    { u"actionBarDivider", 13 },
    { u"actionBarItemBackground", 13 },
    { u"actionModeSplitBackground", 13 },
    { u"textAppearanceListItem", 13 },
    { u"textAppearanceListItemSmall", 13 },
    { u"targetDescriptions", 13 },
    { u"directionDescriptions", 13 },
    { u"overridesImplicitlyEnabledSubtype", 13 },
    { u"listPreferredItemPaddingLeft", 13 },
    { u"listPreferredItemPaddingRight", 13 },
    { u"requiresFadingEdge", 13 },
    { u"publicKey", 13 },
    { u"parentActivityName", 16 },
    { u"isolatedProcess", 16 },
    { u"importantForAccessibility", 16 },
    { u"keyboardLayout", 16 },
    { u"fontFamily", 16 },
    { u"mediaRouteButtonStyle", 16 },
    { u"mediaRouteTypes", 16 },
    { u"supportsRtl", 17 },
    { u"textDirection", 17 },
    { u"textAlignment", 17 },
    { u"layoutDirection", 17 },
    { u"paddingStart", 17 },
    { u"paddingEnd", 17 },
    { u"layout_marginStart", 17 },
    { u"layout_marginEnd", 17 },
    { u"layout_toStartOf", 17 },
    { u"layout_toEndOf", 17 },
    { u"layout_alignStart", 17 },
    { u"layout_alignEnd", 17 },
    { u"layout_alignParentStart", 17 },
    { u"layout_alignParentEnd", 17 },
    { u"listPreferredItemPaddingStart", 17 },
    { u"listPreferredItemPaddingEnd", 17 },
    { u"singleUser", 17 },
    { u"presentationTheme", 17 },
    { u"subtypeId", 17 },
    { u"initialKeyguardLayout", 17 },
    { u"widgetCategory", 17 },
    { u"permissionGroupFlags", 17 },
    { u"labelFor", 17 },
    { u"permissionFlags", 17 },
    { u"checkedTextViewStyle", 17 },
    { u"showOnLockScreen", 17 },
    { u"format12Hour", 17 },
    { u"format24Hour", 17 },
    { u"timeZone", 17 },
    { u"mipMap", 18 },
    { u"mirrorForRtl", 18 },
    { u"windowOverscan", 18 },
    { u"requiredForAllUsers", 18 },
    { u"indicatorStart", 18 },
    { u"indicatorEnd", 18 },
    { u"childIndicatorStart", 18 },
    { u"childIndicatorEnd", 18 },
    { u"restrictedAccountType", 18 },
    { u"requiredAccountType", 18 },
    { u"canRequestTouchExplorationMode", 18 },
    { u"canRequestEnhancedWebAccessibility", 18 },
    { u"canRequestFilterKeyEvents", 18 },
    { u"layoutMode", 18 },
    { u"keySet", 19 },
    { u"targetId", 19 },
    { u"fromScene", 19 },
    { u"toScene", 19 },
    { u"transition", 19 },
    { u"transitionOrdering", 19 },
    { u"fadingMode", 19 },
    { u"startDelay", 19 },
    { u"ssp", 19 },
    { u"sspPrefix", 19 },
    { u"sspPattern", 19 },
    { u"addPrintersActivity", 19 },
    { u"vendor", 19 },
    { u"category", 19 },
    { u"isAsciiCapable", 19 },
    { u"autoMirrored", 19 },
    { u"supportsSwitchingToNextInputMethod", 19 },
    { u"requireDeviceUnlock", 19 },
    { u"apduServiceBanner", 19 },
    { u"accessibilityLiveRegion", 19 },
    { u"windowTranslucentStatus", 19 },
    { u"windowTranslucentNavigation", 19 },
    { u"advancedPrintOptionsActivity", 19 },
    { u"banner", 20 },
    { u"windowSwipeToDismiss", 20 },
    { u"isGame", 20 },
    { u"allowEmbedded", 20 },
    { u"setupActivity", 20 },
    { u"fastScrollStyle", 21 },
    { u"windowContentTransitions", 21 },
    { u"windowContentTransitionManager", 21 },
    { u"translationZ", 21 },
    { u"tintMode", 21 },
    { u"controlX1", 21 },
    { u"controlY1", 21 },
    { u"controlX2", 21 },
    { u"controlY2", 21 },
    { u"transitionName", 21 },
    { u"transitionGroup", 21 },
    { u"viewportWidth", 21 },
    { u"viewportHeight", 21 },
    { u"fillColor", 21 },
    { u"pathData", 21 },
    { u"strokeColor", 21 },
    { u"strokeWidth", 21 },
    { u"trimPathStart", 21 },
    { u"trimPathEnd", 21 },
    { u"trimPathOffset", 21 },
    { u"strokeLineCap", 21 },
    { u"strokeLineJoin", 21 },
    { u"strokeMiterLimit", 21 },
    { u"colorControlNormal", 21 },
    { u"colorControlActivated", 21 },
    { u"colorButtonNormal", 21 },
    { u"colorControlHighlight", 21 },
    { u"persistableMode", 21 },
    { u"titleTextAppearance", 21 },
    { u"subtitleTextAppearance", 21 },
    { u"slideEdge", 21 },
    { u"actionBarTheme", 21 },
    { u"textAppearanceListItemSecondary", 21 },
    { u"colorPrimary", 21 },
    { u"colorPrimaryDark", 21 },
    { u"colorAccent", 21 },
    { u"nestedScrollingEnabled", 21 },
    { u"windowEnterTransition", 21 },
    { u"windowExitTransition", 21 },
    { u"windowSharedElementEnterTransition", 21 },
    { u"windowSharedElementExitTransition", 21 },
    { u"windowAllowReturnTransitionOverlap", 21 },
    { u"windowAllowEnterTransitionOverlap", 21 },
    { u"sessionService", 21 },
    { u"stackViewStyle", 21 },
    { u"switchStyle", 21 },
    { u"elevation", 21 },
    { u"excludeId", 21 },
    { u"excludeClass", 21 },
    { u"hideOnContentScroll", 21 },
    { u"actionOverflowMenuStyle", 21 },
    { u"documentLaunchMode", 21 },
    { u"maxRecents", 21 },
    { u"autoRemoveFromRecents", 21 },
    { u"stateListAnimator", 21 },
    { u"toId", 21 },
    { u"fromId", 21 },
    { u"reversible", 21 },
    { u"splitTrack", 21 },
    { u"targetName", 21 },
    { u"excludeName", 21 },
    { u"matchOrder", 21 },
    { u"windowDrawsSystemBarBackgrounds", 21 },
    { u"statusBarColor", 21 },
    { u"navigationBarColor", 21 },
    { u"contentInsetStart", 21 },
    { u"contentInsetEnd", 21 },
    { u"contentInsetLeft", 21 },
    { u"contentInsetRight", 21 },
    { u"paddingMode", 21 },
    { u"layout_rowWeight", 21 },
    { u"layout_columnWeight", 21 },
    { u"translateX", 21 },
    { u"translateY", 21 },
    { u"selectableItemBackgroundBorderless", 21 },
    { u"elegantTextHeight", 21 },
    { u"searchKeyphraseId", 21 },
    { u"searchKeyphrase", 21 },
    { u"searchKeyphraseSupportedLocales", 21 },
    { u"windowTransitionBackgroundFadeDuration", 21 },
    { u"overlapAnchor", 21 },
    { u"progressTint", 21 },
    { u"progressTintMode", 21 },
    { u"progressBackgroundTint", 21 },
    { u"progressBackgroundTintMode", 21 },
    { u"secondaryProgressTint", 21 },
    { u"secondaryProgressTintMode", 21 },
    { u"indeterminateTint", 21 },
    { u"indeterminateTintMode", 21 },
    { u"backgroundTint", 21 },
    { u"backgroundTintMode", 21 },
    { u"foregroundTint", 21 },
    { u"foregroundTintMode", 21 },
    { u"buttonTint", 21 },
    { u"buttonTintMode", 21 },
    { u"thumbTint", 21 },
    { u"thumbTintMode", 21 },
    { u"fullBackupOnly", 21 },
    { u"propertyXName", 21 },
    { u"propertyYName", 21 },
    { u"relinquishTaskIdentity", 21 },
    { u"tileModeX", 21 },
    { u"tileModeY", 21 },
    { u"actionModeShareDrawable", 21 },
    { u"actionModeFindDrawable", 21 },
    { u"actionModeWebSearchDrawable", 21 },
    { u"transitionVisibilityMode", 21 },
    { u"minimumHorizontalAngle", 21 },
    { u"minimumVerticalAngle", 21 },
    { u"maximumAngle", 21 },
    { u"searchViewStyle", 21 },
    { u"closeIcon", 21 },
    { u"goIcon", 21 },
    { u"searchIcon", 21 },
    { u"voiceIcon", 21 },
    { u"commitIcon", 21 },
    { u"suggestionRowLayout", 21 },
    { u"queryBackground", 21 },
    { u"submitBackground", 21 },
    { u"buttonBarPositiveButtonStyle", 21 },
    { u"buttonBarNeutralButtonStyle", 21 },
    { u"buttonBarNegativeButtonStyle", 21 },
    { u"popupElevation", 21 },
    { u"actionBarPopupTheme", 21 },
    { u"multiArch", 21 },
    { u"touchscreenBlocksFocus", 21 },
    { u"windowElevation", 21 },
    { u"launchTaskBehindTargetAnimation", 21 },
    { u"launchTaskBehindSourceAnimation", 21 },
    { u"restrictionType", 21 },
    { u"dayOfWeekBackground", 21 },
    { u"dayOfWeekTextAppearance", 21 },
    { u"headerMonthTextAppearance", 21 },
    { u"headerDayOfMonthTextAppearance", 21 },
    { u"headerYearTextAppearance", 21 },
    { u"yearListItemTextAppearance", 21 },
    { u"yearListSelectorColor", 21 },
    { u"calendarTextColor", 21 },
    { u"recognitionService", 21 },
    { u"timePickerStyle", 21 },
    { u"timePickerDialogTheme", 21 },
    { u"headerTimeTextAppearance", 21 },
    { u"headerAmPmTextAppearance", 21 },
    { u"numbersTextColor", 21 },
    { u"numbersBackgroundColor", 21 },
    { u"numbersSelectorColor", 21 },
    { u"amPmTextColor", 21 },
    { u"amPmBackgroundColor", 21 },
    { u"searchKeyphraseRecognitionFlags", 21 },
    { u"checkMarkTint", 21 },
    { u"checkMarkTintMode", 21 },
    { u"popupTheme", 21 },
    { u"toolbarStyle", 21 },
    { u"windowClipToOutline", 21 },
    { u"datePickerDialogTheme", 21 },
    { u"showText", 21 },
    { u"windowReturnTransition", 21 },
    { u"windowReenterTransition", 21 },
    { u"windowSharedElementReturnTransition", 21 },
    { u"windowSharedElementReenterTransition", 21 },
    { u"resumeWhilePausing", 21 },
    { u"datePickerMode", 21 },
    { u"timePickerMode", 21 },
    { u"inset", 21 },
    { u"letterSpacing", 21 },
    { u"fontFeatureSettings", 21 },
    { u"outlineProvider", 21 },
    { u"contentAgeHint", 21 },
    { u"country", 21 },
    { u"windowSharedElementsUseOverlay", 21 },
    { u"reparent", 21 },
    { u"reparentWithOverlay", 21 },
    { u"ambientShadowAlpha", 21 },
    { u"spotShadowAlpha", 21 },
    { u"navigationIcon", 21 },
    { u"navigationContentDescription", 21 },
    { u"fragmentExitTransition", 21 },
    { u"fragmentEnterTransition", 21 },
    { u"fragmentSharedElementEnterTransition", 21 },
    { u"fragmentReturnTransition", 21 },
    { u"fragmentSharedElementReturnTransition", 21 },
    { u"fragmentReenterTransition", 21 },
    { u"fragmentAllowEnterTransitionOverlap", 21 },
    { u"fragmentAllowReturnTransitionOverlap", 21 },
    { u"patternPathData", 21 },
    { u"strokeAlpha", 21 },
    { u"fillAlpha", 21 },
    { u"windowActivityTransitions", 21 },
    { u"colorEdgeEffect", 21 }
};

size_t findAttributeSdkLevel(const ResourceName& name) {
    if (name.package != u"android" && name.type != ResourceType::kAttr) {
        return 0;
    }

    auto iter = sAttrMap.find(name.entry);
    if (iter != sAttrMap.end()) {
        return iter->second;
    }
    return SDK_LOLLIPOP_MR1;
}

} // namespace aapt