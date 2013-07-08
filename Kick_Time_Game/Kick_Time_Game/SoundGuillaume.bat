SET SoundBuilder="..\..\Kick_Time_Sound_Builder\Kick_Time_Sound_Builder\Release\Kick_Time_Sound_Builder.exe"

SET Dir="C:\Users\Administrateur\Desktop\kick-time\Kick_Time_Game\Kick_Time_Game\
SET DirCode=%Dir%Kick_Time_Game"
SET FileSound=%Dir%Ressources\Sounds\sounds.txt"

%AnimationBuilder% %DirCharacters% %DirCode%
%CharacterBuilder% %DirCharacters% %DirCode%
%ColliderBuilder% %DirCharacters% %DirCode%
%FontBuilder% %FileFont% %DirCode%
%LevelBuilder% %DirLevels% %DirCode%
%SoundBuilder% %FileSound% %DirCode%

pause