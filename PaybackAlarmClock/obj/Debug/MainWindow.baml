   M S B A M L   `   `   `  ����a  ]PresentationFramework.Aero, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35gJclr-namespace:Microsoft.Windows.Themes;assembly=PresentationFramework.AeroMicrosoft.Windows.Themes  5   	    PaybackAlarmClock"   PaybackAlarmClock.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   ]ThemesJclr-namespace:Microsoft.Windows.Themes;assembly=PresentationFramework.Aero     5   	     � Title$  还贷闹钟v1.0��5   	   $	��600��6   $	��400��6'    � WindowStartupLocation$ CenterScreen=�63    � 
ResizeMode$ NoResize=�6X   ���	#FFACC5E0 � 	Resources 5         ContentAlignmentStyle �� Property �� Value  TextAlignmentStyle  CheckBoxStroke �� Color  CheckRadioFocusVisual J� SnapsToDevicePixels �� StrokeDashArray  RadioButtonStyle1	 �� 
TargetType
 �� 
TargetType �� 
Background �� Bullet+   %Microsoft.Windows.Themes.BulletChrome   BorderBrush   
Background d� 	IsChecked   	IsChecked   IsRound J� IsMouseOver   RenderMouseOver   RenderPressed ��Name �� ImageSource ��Name ��Name �� Triggers P� Property P� Value �� 
TargetName  RadioButtonStyle2��%�  &	        &	 r     &	 �     &	     &	 �    7  7  &	     7  7  �� 5   
   .�5      ��  � ��$ Center=�6A   6R   �� 5	       � ��$
 Left=�6C   6R   5
      �� 5   
   .�5      ��  � ��$ Center=�6:   6K   �� 5       � ��$
 Left=�6<   6K   5      �� 5   
   $ #8E8F8F��61   �� 5   
   .�5      ��  � �� 5      �� 5      .R�5      �� $��14,0,0,0q�6$    . #��� ��6Q   $��1��6�   $	 1 2R�6�   5      5      5      �� 5   
   "	 	�6*   .�5      ��  � ��# � ��6+   �� 5       � �� �#F4F4F46+   �� 5       � ��8   6,   �� 5       � ��$ 1q�60   �� 5       � �� 5      �� 5       "
 	�6&   .R�5!      �� 
 ����  5"        5#   "   # z��66   # z��6b   # z 6�    . # z 6�   # z��6�   $y�	Collapsed=�6  ._�5%      �� $ border��6%   
���   �$��1q�6I   $
��Left=�6]   $��60��6x   $	��Top=�6�   $��66��6�   ��5&   "   �� 5'   &   $ imgs/灰块.png��61   ._�5)   "   � .+�5*   &   �� $ image��6,   $��imgs/home_r.png��6;   $��Center=�6T   $��32��6q   $��32��6|   $	��Top=�6�   �� 5+   &   $ label��6,   $��Bottom=�6;   $��Center=�6V   $��主页��6s   $��Bottom=�6�   $��Center=�6�   
���   �$��Normal"�6�   �� 5,   &   #��z��67   #��z��6z   ��. #��z��6�   $y�	Collapsed=�6�   5-   #   5.      5/       50      P� 51       �@d�	IsChecked$
 TrueY�6;   . �52   "   �� $ border��6?    � �� 53   &   �� 54   *   $ imgs/蓝块.png��65   56   #   �� 57   "   $ label��6?    � ��
 �����6R   58      P� 59       �@d�	IsChecked$ falseY�6;   . �5:   "   �� $ border��6?    � �� 5;   &   �� 5<   *   $ imgs/灰块.png��65   5>   #   �� 5?   "   $ label��6?    � ��
 �   �6R   5@      P� 5A       � �� . . �5B   "   �� 8   �@�FocusVisualStyle6E   �� 5C   "    � ��$ 4,0,0,0q�6<   5D      P� 5E       � {� .  . �5F   "   �� # � ��6?    � ��5G      5I      5K      5L      �� 5M   
   "	 	�6*   .�5N      ��  � ��# � ��6+   �� 5O       � �� �#F4F4F46+   �� 5P       � ��8   6,   �� 5Q       � ��$ 1q�60   �� 5R       � �� 5S      �� 5T      "
 	�6&   .R�5U      �� 
 ����  5V        5W   "   # z��66   # z��6b   # z 6�    . # z 6�   # z��6�   $y�	Collapsed=�6  ._�5Y      �� $ border��6%   
���   �$��1q�6I   $
��Left=�6]   $��60��6x   $	��Top=�6�   $��66��6�   ��5Z   "   �� 5[   &   $ imgs/灰块.png��61   ._�5]   "   � .+�5^   &   �� $ image��6,   $��imgs/config_r.png��6;   $��Center=�6V   $��32��6s   $��32��6~   $	��Top=�6�   �� 5_   &   $ label��6,   $��Bottom=�6;   $��Center=�6V   $��计划��6s   $��Bottom=�6�   $��Center=�6�   
���   �$��Normal"�6�   �� 5`   &   #��z��67   #��z��6z   ��. #��z��6�   $y�	Collapsed=�6�   5a   #   5b      5c       5d      P� 5e       �@d�	IsChecked$
 TrueY�6;   . �5f   "   �� $ border��6?    � �� 5g   &   �� 5h   *   $ imgs/蓝块.png��65   5j   #   �� 5k   "   $ label��6?    � ��
 �����6R   5l      P� 5m       �@d�	IsChecked$ falseY�6;   . �5n   "   �� $ border��6?    � �� 5o   &   �� 5p   *   $ imgs/灰块.png��65   5r   #   �� 5s   "   $ label��6?    � ��
 �   �6R   5t      P� 5u       � �� . . �5v   "   �� 8   �@�FocusVisualStyle6E   �� 5w   "    � ��$ 4,0,0,0q�6<   5x      P� 5y       � {� .  . �5z   "   �� # � ��6?    � ��5{      5}      5      5�      5�      .��5�      � .+�5�   
   ]� .+�5�      �� $	��Top=�6    �� Orientation$ 
Horizontal=�6.   .+�5�      	� -   5         	�Name$ home_radiobtn��5�      $	��3,7q�65   $
��auto��6B   $
��auto��6O   #��[ 6]   $
 TrueY�6�   .��6�   	主界面5�      	� 5�      -   5        $ config_radiobtn��5�      $	��3,7q�67   $
��auto��6D   $
��auto��6Q   #��[ 6_   .��6�   计划5�      5�      �� 5�      -   5         ��Name$ main_tabcotrol��5�      .@�5�      �� $��	主界面��6   $y�	Collapsed=�6'   .��5�      ]� .+�5�      �� -   5          ��Name$  main_listbox��5�   "   .@�5�      �� $	��3,7q�6*   ���	#FFF7ED0D.��5�   "   �� $ 
Horizontal=�6-   .+�5�   &   �� $	��3,7q�60   #��[ 6=   房贷6m   �� 5�   &   $	��3,7q�60   #��[ 6=   	2800元6p   �� 5�   &   $	��3,7q�60   #��[ 6=   " 距本次还款1天(每月11号)6y   �� 5�   &   $	��3,7q�60   #��[ 6=   未还6m   �� 5�   &   -   5        $y�Visible=�5�   -   $	��3,7q�6B   $��还款��6O   6\   5�   #   5�      �� 5�      $	��3,7q�6*   ���	#FF05F710.��5�   "   �� $ 
Horizontal=�6-   .+�5�   &   �� $	��3,7q�60   #��[ 6=   车贷6m   �� 5�   &   $	��3,7q�60   #��[ 6=   	1700元6p   �� 5�   &   $	��3,7q�60   #��[ 6=    距下次还款30(每月10号)6y   �� 5�   &   $	��3,7q�60   #��[ 6=   已还6m   �� 5�   &   -   5        $y�	Collapsed=�5�   -   $	��3,7q�6D   $��还款��6Q   6^   5�   #   5�      �� 5�      $	��3,7q�6*   ���	#FFFB1F09.��5�   "   �� $ 
Horizontal=�6-   .+�5�   &   �� $	��3,7q�60   #��[ 6=   房租6m   �� 5�   &   $	��3,7q�60   #��[ 6=   	1300元6p   �� 5�   &   $	��3,7q�60   #��[ 6=   $"本次还款逾期1天(每月9号)6y   �� 5�   &   $	��3,7q�60   #��[ 6=   逾期6m   �� 5�   &   -   5        $y�Visible=�5�   -   $	��3,7q�6B   $��还款��6O   6\   5�   #   5�      5�      5�      5�      �� 5�      $��还贷设定��6   $y�	Collapsed=�6(   .��5�      ]� 6"   5�      5�      5�      5�      5�      