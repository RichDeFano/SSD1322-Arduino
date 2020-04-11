#include "bitmaps.h"
#include "bitmapLetter.h"
#include "textStorage.h"


/*
  Function Name: createDictionary
  Funciton Parameters: (bitmapLetter alphabet[]) - The array containing a pointer to each letter bitmap/
  						(int width) - The width of a single character
  						(int height) - The height of a single character
  Function Description: Draw Each frame of a full bitmap with a certain delay.
  */
static void bitmapLetter::createDictionary(bitmapLetter alphabet[], int width, int height){
size_t siz = sizeof(zelda_font_20);

bitmapLetter l20(width,height,0x20,siz,zelda_font_20);
bitmapLetter l21(width,height,0x21,siz,zelda_font_21);
bitmapLetter l22(width,height,0x22,siz,zelda_font_22);
bitmapLetter l23(width,height,0x23,siz,zelda_font_23);
bitmapLetter l24(width,height,0x24,siz,zelda_font_24);
bitmapLetter l25(width,height,0x25,siz,zelda_font_25);
bitmapLetter l26(width,height,0x26,siz,zelda_font_26);
bitmapLetter l27(width,height,0x27,siz,zelda_font_27);
bitmapLetter l28(width,height,0x28,siz,zelda_font_28);
bitmapLetter l29(width,height,0x29,siz,zelda_font_29);
bitmapLetter l2A(width,height,0x2A,siz,zelda_font_2A);
bitmapLetter l2B(width,height,0x2B,siz,zelda_font_2B);
bitmapLetter l2C(width,height,0x2C,siz,zelda_font_2C);
bitmapLetter l2D(width,height,0x2D,siz,zelda_font_2D);
bitmapLetter l2E(width,height,0x2E,siz,zelda_font_2E);
bitmapLetter l2F(width,height,0x2F,siz,zelda_font_2F);

bitmapLetter l30(width,height,0x30,siz,zelda_font_30);
bitmapLetter l31(width,height,0x31,siz,zelda_font_31);
bitmapLetter l32(width,height,0x32,siz,zelda_font_32);
bitmapLetter l33(width,height,0x33,siz,zelda_font_33);
bitmapLetter l34(width,height,0x34,siz,zelda_font_34);
bitmapLetter l35(width,height,0x35,siz,zelda_font_35);
bitmapLetter l36(width,height,0x36,siz,zelda_font_36);
bitmapLetter l37(width,height,0x37,siz,zelda_font_37);
bitmapLetter l38(width,height,0x38,siz,zelda_font_38);
bitmapLetter l39(width,height,0x39,siz,zelda_font_39);
bitmapLetter l3A(width,height,0x3A,siz,zelda_font_3A);
bitmapLetter l3B(width,height,0x3B,siz,zelda_font_3B);
bitmapLetter l3C(width,height,0x3C,siz,zelda_font_3C);
bitmapLetter l3D(width,height,0x3D,siz,zelda_font_3D);
bitmapLetter l3E(width,height,0x3E,siz,zelda_font_3E);
bitmapLetter l3F(width,height,0x3F,siz,zelda_font_3F);

bitmapLetter l40(width,height,0x40,siz,zelda_font_40);
bitmapLetter l41(width,height,0x41,siz,zelda_font_41);
bitmapLetter l42(width,height,0x42,siz,zelda_font_42);
bitmapLetter l43(width,height,0x43,siz,zelda_font_43);
bitmapLetter l44(width,height,0x44,siz,zelda_font_44);
bitmapLetter l45(width,height,0x45,siz,zelda_font_45);
bitmapLetter l46(width,height,0x46,siz,zelda_font_46);
bitmapLetter l47(width,height,0x47,siz,zelda_font_47);
bitmapLetter l48(width,height,0x48,siz,zelda_font_48);
bitmapLetter l49(width,height,0x49,siz,zelda_font_49);
bitmapLetter l4A(width,height,0x4A,siz,zelda_font_4A);
bitmapLetter l4B(width,height,0x4B,siz,zelda_font_4B);
bitmapLetter l4C(width,height,0x4C,siz,zelda_font_4C);
bitmapLetter l4D(width,height,0x4D,siz,zelda_font_4D);
bitmapLetter l4E(width,height,0x4E,siz,zelda_font_4E);
bitmapLetter l4F(width,height,0x4F,siz,zelda_font_4F);

bitmapLetter l50(width,height,0x50,siz,zelda_font_50);
bitmapLetter l51(width,height,0x51,siz,zelda_font_51);
bitmapLetter l52(width,height,0x52,siz,zelda_font_52);
bitmapLetter l53(width,height,0x53,siz,zelda_font_53);
bitmapLetter l54(width,height,0x54,siz,zelda_font_54);
bitmapLetter l55(width,height,0x55,siz,zelda_font_55);
bitmapLetter l56(width,height,0x56,siz,zelda_font_56);
bitmapLetter l57(width,height,0x57,siz,zelda_font_57);
bitmapLetter l58(width,height,0x58,siz,zelda_font_58);
bitmapLetter l59(width,height,0x59,siz,zelda_font_59);
bitmapLetter l5A(width,height,0x5A,siz,zelda_font_5A);
bitmapLetter l5B(width,height,0x5B,siz,zelda_font_5B);
bitmapLetter l5C(width,height,0x5C,siz,zelda_font_5C);
bitmapLetter l5D(width,height,0x5D,siz,zelda_font_5D);
bitmapLetter l5E(width,height,0x5E,siz,zelda_font_5E);
bitmapLetter l5F(width,height,0x5F,siz,zelda_font_5F);

bitmapLetter l60(width,height,0x60,siz,zelda_font_60);
bitmapLetter l61(width,height,0x61,siz,zelda_font_61);
bitmapLetter l62(width,height,0x62,siz,zelda_font_62);
bitmapLetter l63(width,height,0x63,siz,zelda_font_63);
bitmapLetter l64(width,height,0x64,siz,zelda_font_64);
bitmapLetter l65(width,height,0x65,siz,zelda_font_65);
bitmapLetter l66(width,height,0x66,siz,zelda_font_66);
bitmapLetter l67(width,height,0x67,siz,zelda_font_67);
bitmapLetter l68(width,height,0x68,siz,zelda_font_68);
bitmapLetter l69(width,height,0x69,siz,zelda_font_69);
bitmapLetter l6A(width,height,0x6A,siz,zelda_font_6A);
bitmapLetter l6B(width,height,0x6B,siz,zelda_font_6B);
bitmapLetter l6C(width,height,0x6C,siz,zelda_font_6C);
bitmapLetter l6D(width,height,0x6D,siz,zelda_font_6D);
bitmapLetter l6E(width,height,0x6E,siz,zelda_font_6E);
bitmapLetter l6F(width,height,0x6F,siz,zelda_font_6F);

bitmapLetter l70(width,height,0x70,siz,zelda_font_70);
bitmapLetter l71(width,height,0x71,siz,zelda_font_71);
bitmapLetter l72(width,height,0x72,siz,zelda_font_72);
bitmapLetter l73(width,height,0x73,siz,zelda_font_73);
bitmapLetter l74(width,height,0x74,siz,zelda_font_74);
bitmapLetter l75(width,height,0x75,siz,zelda_font_75);
bitmapLetter l76(width,height,0x76,siz,zelda_font_76);
bitmapLetter l77(width,height,0x77,siz,zelda_font_77);
bitmapLetter l78(width,height,0x78,siz,zelda_font_78);
bitmapLetter l79(width,height,0x79,siz,zelda_font_79);
bitmapLetter l7A(width,height,0x7A,siz,zelda_font_7A);
////////////////////////////////////////////////////////////
alphabet[l21.getAscii()] = l21;
alphabet[l22.getAscii()] = l22;
alphabet[l23.getAscii()] = l23;
alphabet[l24.getAscii()] = l24;
alphabet[l25.getAscii()] = l25;
alphabet[l26.getAscii()] = l26;
alphabet[l27.getAscii()] = l27;
alphabet[l28.getAscii()] = l28;
alphabet[l29.getAscii()] = l29;
alphabet[l2A.getAscii()] = l2A;
alphabet[l2B.getAscii()] = l2B;
alphabet[l2C.getAscii()] = l2C;
alphabet[l2D.getAscii()] = l2D;
alphabet[l2E.getAscii()] = l2E;
alphabet[l2F.getAscii()] = l2F;

alphabet[l30.getAscii()] = l30;
alphabet[l31.getAscii()] = l31;
alphabet[l32.getAscii()] = l32;
alphabet[l33.getAscii()] = l33;
alphabet[l34.getAscii()] = l34;
alphabet[l35.getAscii()] = l35;
alphabet[l36.getAscii()] = l36;
alphabet[l37.getAscii()] = l37;
alphabet[l38.getAscii()] = l38;
alphabet[l39.getAscii()] = l39;
alphabet[l3A.getAscii()] = l3A;
alphabet[l3B.getAscii()] = l3B;
alphabet[l3C.getAscii()] = l3C;
alphabet[l3D.getAscii()] = l3D;
alphabet[l3E.getAscii()] = l3E;
alphabet[l3F.getAscii()] = l3F;

alphabet[l40.getAscii()] = l40;
alphabet[l41.getAscii()] = l41;
alphabet[l42.getAscii()] = l42;
alphabet[l43.getAscii()] = l43;
alphabet[l44.getAscii()] = l44;
alphabet[l45.getAscii()] = l45;
alphabet[l46.getAscii()] = l46;
alphabet[l47.getAscii()] = l47;
alphabet[l48.getAscii()] = l48;
alphabet[l49.getAscii()] = l49;
alphabet[l4A.getAscii()] = l4A;
alphabet[l4B.getAscii()] = l4B;
alphabet[l4C.getAscii()] = l4C;
alphabet[l4D.getAscii()] = l4D;
alphabet[l4E.getAscii()] = l4E;
alphabet[l4F.getAscii()] = l4F;

alphabet[l50.getAscii()] = l50;
alphabet[l51.getAscii()] = l51;
alphabet[l52.getAscii()] = l52;
alphabet[l53.getAscii()] = l53;
alphabet[l54.getAscii()] = l54;
alphabet[l55.getAscii()] = l55;
alphabet[l56.getAscii()] = l56;
alphabet[l57.getAscii()] = l57;
alphabet[l58.getAscii()] = l58;
alphabet[l59.getAscii()] = l59;
alphabet[l5A.getAscii()] = l5A;
alphabet[l5B.getAscii()] = l5B;
alphabet[l5C.getAscii()] = l5C;
alphabet[l5D.getAscii()] = l5D;
alphabet[l5E.getAscii()] = l5E;
alphabet[l5F.getAscii()] = l5F;

alphabet[l60.getAscii()] = l60;
alphabet[l61.getAscii()] = l61;
alphabet[l62.getAscii()] = l62;
alphabet[l63.getAscii()] = l63;
alphabet[l64.getAscii()] = l64;
alphabet[l65.getAscii()] = l65;
alphabet[l66.getAscii()] = l66;
alphabet[l67.getAscii()] = l67;
alphabet[l68.getAscii()] = l68;
alphabet[l69.getAscii()] = l69;
alphabet[l6A.getAscii()] = l6A;
alphabet[l6B.getAscii()] = l6B;
alphabet[l6C.getAscii()] = l6C;
alphabet[l6D.getAscii()] = l6D;
alphabet[l6E.getAscii()] = l6E;
alphabet[l6F.getAscii()] = l6F;

alphabet[l70.getAscii()] = l70;
alphabet[l71.getAscii()] = l71;
alphabet[l72.getAscii()] = l72;
alphabet[l73.getAscii()] = l73;
alphabet[l74.getAscii()] = l74;
alphabet[l75.getAscii()] = l75;
alphabet[l76.getAscii()] = l76;
alphabet[l77.getAscii()] = l77;
alphabet[l78.getAscii()] = l78;
alphabet[l79.getAscii()] = l79;
alphabet[l7A.getAscii()] = l7A;


}

static void bitmapLetter::createSmallDictionary(bitmapLetter alphabet[], int width, int height){
bitmapLetter smallZero(width,height,0x30,sizeof(small_zero),small_zero);
bitmapLetter smallOne(width,height,0x31,sizeof(small_zero),small_one);
bitmapLetter smallTwo(width,height,0x32,sizeof(small_zero),small_two);
bitmapLetter smallThree(width,height,0x33,sizeof(small_zero),small_three);
bitmapLetter smallFour(width,height,0x34,sizeof(small_zero),small_four);
bitmapLetter smallFive(width,height,0x35,sizeof(small_zero),small_five);
bitmapLetter smallSix(width,height,0x36,sizeof(small_zero),small_six);
bitmapLetter smallSeven(width,height,0x37,sizeof(small_zero),small_seven);
bitmapLetter smallEight(width,height,0x38,sizeof(small_zero),small_eight);
bitmapLetter smallNine(width,height,0x39,sizeof(small_zero),small_nine);
bitmapLetter smallSemicolon(width/2,height,0x3A,sizeof(small_zero),small_semicolon);
/////////////////////////////////////////////////////////////////
alphabet[smallZero.getAscii() - 0x30] = smallZero;
alphabet[smallOne.getAscii() - 0x30] = smallOne;
alphabet[smallTwo.getAscii() - 0x30] = smallTwo;
alphabet[smallThree.getAscii() - 0x30] = smallThree;
alphabet[smallFour.getAscii() - 0x30] = smallFour;
alphabet[smallFive.getAscii() - 0x30] = smallFive;
alphabet[smallSix.getAscii() - 0x30] = smallSix;
alphabet[smallSeven.getAscii() - 0x30] = smallSeven;
alphabet[smallEight.getAscii() - 0x30] = smallEight;
alphabet[smallNine.getAscii() - 0x30] = smallNine;
alphabet[smallSemicolon.getAscii() - 0x30] = smallSemicolon;

}
