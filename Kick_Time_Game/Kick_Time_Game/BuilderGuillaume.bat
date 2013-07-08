SET AnimationBuilder="..\..\Kick_Time_Animation_Builder\Kick_Time_Animation_Builder\Release\Kick_Time_Animation_Builder.exe"
SET CharacterBuilder="..\..\Kick_Time_Character_Builder\Kick_Time_Character_Builder\Release\Kick_Time_Character_Builder.exe"
SET ColliderBuilder="..\..\Kick_Time_Collider_Builder\Kick_Time_Collider_Builder\Release\Kick_Time_Collider_Builder.exe"
SET FontBuilder="..\..\Kick_Time_Font_Builder\Kick_Time_Font_Builder\Release\Kick_Time_Font_Builder.exe"
SET LevelBuilder="..\..\Kick_Time_Level_Builder\Kick_Time_Level_Builder\Release\Kick_Time_Level_Builder.exe"
SET SoundBuilder="..\..\Kick_Time_Sound_Builder\Kick_Time_Sound_Builder\Release\Kick_Time_Sound_Builder.exe"

SET Dir="C:\Users\Administrateur\Desktop\kick-time\Kick_Time_Game\Kick_Time_Game\
SET DirCode=%Dir%Kick_Time_Game"
SET DirCharacters=%Dir%Ressources\Characters"
SET FileFont=%Dir%Ressources\Fonts\fonts.txt"
SET DirLevels=%Dir%Ressources\Levels"
SET FileSound=%Dir%Ressources\Sounds\sounds.txt"

%AnimationBuilder% %DirCharacters% %DirCode%
%CharacterBuilder% %DirCharacters% %DirCode%
%ColliderBuilder% %DirCharacters% %DirCode%
%FontBuilder% %FileFont% %DirCode%
%LevelBuilder% %DirLevels% %DirCode%
%SoundBuilder% %FileSound% %DirCode%

pause