#include "gtest/gtest.h"
#include "../TestUtils.h"
#include "Day6/TuningTrouble.h"

using namespace std;
using namespace TestUtils;
using namespace TuningTrouble;

// const string FILE_PATH(TEST_DIRECTORY + "Day6/Files/");

TEST(TuningTroubleTest, SmallInputPart1) {
  int startIndex = DetectFirstStartOfPacketMarker("mjqjpqmgbljsphdztnvjfqwrcgsmlb");
  EXPECT_EQ(startIndex, 7);
}

TEST(TuningTroubleTest, SmallInput2Part1) {
  int startIndex = DetectFirstStartOfPacketMarker("bvwbjplbgvbhsrlpgdmjqwftvncz");
  EXPECT_EQ(startIndex, 5);
}

TEST(TuningTroubleTest, SmallInput3Part1) {
  int startIndex = DetectFirstStartOfPacketMarker("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg");
  EXPECT_EQ(startIndex, 10);
}

TEST(TuningTroubleTest, SmallInput4Part1) {
  int startIndex = DetectFirstStartOfPacketMarker("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw");
  EXPECT_EQ(startIndex, 11);
}

TEST(TuningTroubleTest, Part1) {
  int startIndex = DetectFirstStartOfPacketMarker("dcbcsbblhhgdgssmcmqccdwdvwdvvcfvcfvvpvmmwccdqddshhdppcfpfbbfggfjfvvhzhmmsqswsttcgtctggjllhnnqbnnnldlglplvlbvbzztpzzvpphshwwfhhgssvgsvvpfvfzznbznndqqtsqttnvtvqqqrgqrrgzzlqzzbvzbzmzffnbfnbffcggdcggqhqpqzpqzqbbqvbqbhhtzhhrrrprlrclrcrssqspqpbblggfvvbpvbbssvttsztzpzjjwffnpnfnrrqhqgqrrzqzbzzdpdjpplpclpptltztjtztqthtmmmpsmmpjpqpvvshhsfshhrvrdvdggwssdbbzbttlmlmpprmrmlrrmqrqsshjhjljzjnjllbbvjvnnppqbppqqfffrbfbdfbbqppmtppfttqddtzzwbblqqbddgwgqwqzwwpzwzjjbccdjdwwrggrmrtmrtmrrvpptwwcdcwwsdshhjjhwjwqjwwqsshrrbsblssphspsjpssnsmsqswqwfwjwccdvccrqqnsqnsnwsnsmnmccvcqqfjjfljfljfjgjffjvffvjvhjhfhrfrlrrtpphbhwbbvmmnpndnlljdjfjsffvccnhchwhddrccljllmnnhmnmpnnhtnthnhvnhnwnqqjmmgzzvssphhjljbjwjbwwdnwwdvvzpvvhccvjjlclrrppgjgsshghvvzjvvpvvbjjqhjqqfcqffchcmmvdvtddftdtppfnppcnpnznwwpdpjpnpttlbbmmqfqmffqnfnbffbrbgbwggsmsbbfgbbfbzbtzbbvmmdlmlrlnlwwbswsjjpjhhwqwzqznqzqvvwccwvwwcbbpvvwcvcvzzhzchzccbnccjlljsjbjdbbvqbvvfdfgdfggzfzlzmzrznnqsnncmnnljjtcjcfftrthtrhrgrvvjggzpggrcrpcppggdfggpmmwnmnlmlglvvmjvvddsmsjsnjssqffffctczcjzjjlbbhpbbfdbdzbbsjbjnjbbqqjbqjbjjhwhssmvsschhhwppbjppllprpjrppdpfpgpjptjtptplpnptnptpjjmcmnnnhnjhjlhjlhjlhlwwhwmwjjbhhlfffrbbgvvqwvwswtstmmmfpmfpffmcfcrrqsqzqjjjnpnnztnznddlwdldsdbssstzstswwjtttmmwmsmwssvswszsjzsjjsffmccmfccqzzvpmbbbsqffgzdqbjtzhlqdzhlpwghlstcrcrffrnbwjnqgmbmpgttfmsswdqctlrpdnlsgnlldvbfpwtcptvbwftzcnbbscrrcpnwtmllcvsrmwzzlsdmfctdcwsqdlsnzgfpmzrnswhbqjhstztzzmzpcttsgsggnlhvjmcbbrhgqhsfmglpcbdvmmmnfbtbfrqbpcmttjtnwvznbshwrmznnsvpjqjntlzspljnbwtjcqztsfcqlrggrpzjgjsvqqcrmrjmzwdsshqfhbtfmlwmfvtbcgdmjgtcnphfmfmjlbjzrvjslccftnwcchgdwjnlthlwgldjwqwgdptdjdmzdrrzcdpbfrtdgcspjtqdqvzswwdwrhggdrqjjgwwrbwhhlrpqmszvlvjfqptncjlscvzbgzgmsttlbhbfrctnsphjcrcwlhcgrcrsjbrjvptgfbjgjrvtzmnhpzcgptbmrgvstsltnctjphsjdwpdqblfswzfhgjbpfrptlmhfwcpdlzqccgtdvbzhwngrhlqftmlhjprscflgzpflvvpfsjmlnmbzsrlrshvnsqrhhlqdlzhrcbjjjfrbqcdspwsmltcrtlbdnbnvhbbwgqdcncsztbfwztzdbqgcrnvndmpstpncbwvtctzdpmcpvrgqvjjztfwpvjtdqlvcvdpfzgcghsmbcwtzztmqwdpsprgsmfhphqsqmflrjdqzjscgzlnvcwcrlmpdscnhqpqjfdbdftqgttwntdbpnshdwnmwsrslfgnzlnwwwqgdbfnthhqtvbzsqgzjhhghtmvvfhlmlpbghnsvlttzsjlgndhdqmqqfdlqnbfscsnnqzcdwzdlqcnstcbsffghftqvwrsshgwmlnprhdnnwslwfwtmtfzdjwpmlvvdhjvdwrhvdsmpgrdpnqsjpqmhttrmdwllrmnbznwjwvvpjnnbnfzbdnhjbqqrnzgdqbspbqtwdpgsbwpzfdbpvzfjpsgmztnzrpvvhwlfscfvfpfblvplgdbhvjjpdjtnwrmvpjsphvglpsntvwtqwqvprcgwjltddpjngvmzfzhmqnnwglbzsbrcztpplpsmgmcfgzgpbtgsjrfvdzzcsthznvdpbwvdlcgdhncsjdvpcbbmtrqczctjljdfghsrvrsfjglqqhjttfdhqdqwhzhqrggsjwlldrntwmmbftgqjhpvvctpbtgltnttlhdqbsbwcqmctwlsnhmhncpmnzsllmjhcgnlfgvpcqrwzvsstgwbvjtnrlbblclzdrcwddrwnptqzgwdwtgrfwffpzjmwbqfmmrcfzfzjbwsslbhggtwtcrlhffzgfgrtljgnznnlgzwfmtwwqzhlthvpfclrtmrqfzrggbctzfsmjhrtwzpfrnhwwprnbwmvwvmvnzqpggmzgslctqbqdtvhgzjwzsnblqzmcpnpwllzhvzzmfqzfjlrsrcnjzqdzbpjftljtzvvmrjszvqllnhhgnrnqttnwlvllphjtnmlwqhcvmbsvnwtcdmhsmhdcwqwtvggcqfpdsrsscmhcvfzvdnffrfhdfmgbsghdbpwdwrdmlvsnzwcfchcqvccszdqrbnfvrpbftcwnjmczwgqzmtlmrthlhtjpmchltcmcqwgfgshtvtpmcmpbmlnjmhnpdsljjmjzddnlgtnjqztzsqqlhtqcscjvjncjvfcvsgjhqgzrmtjjcgvvmwswffmlcvlhqhbvrldrvbrfmmqcnqmfzlsghvclrdbsvcbqspgbzmjnlrdhvncnbcfmdlqrssggsmlwwglcjjzmcdwcnrgvvmgjcfbzlncmgqtllgldbdztbtfcjczqtjjlnpqmrgtjsmrbscvqlgqghfbgwccgwrjrzrsbbrqnjcqhllsqmrjtzmjnndwwmdjfhspjpgdcjjpdvwrsgjcfnpllnnnccvnfvqbpddgvbgbsbczmbzrbclczljdmbhpgmhwlqvnjzjwzzfjmsmcchjrqrtmhwlgjsptctlbtdnrqgntcvngcrqdqptfmhbvlhrqchdtwdwbrbqwtswzcrrfndldwmjbczppzrnncvvqsmpvvqcnsvhprhlmrhnjbwdvrbbwwdtmzrqttschrztgjcshlhfbmhmwrrmwgmfshpdhjwgdmcfdvqrmmwgmzbrlgbfltvlzmvqbgvhppdzglqbdlrhjnntnfvtmzjqccmqdbpjqphfggmjqdrndhclcfvqsjrsbcgdhcrbjsdjmwrzvpfpcjwjfdltztfzgmlzqzmztpvbflppgnhdzssznngfjggczdtdmcczjzfsnflpwqrbggmqdbbprfptzcdqvhrvszzjqqjlrlrdpwcnzhvgfhpcdbbgsfmtnszwbhwcdwdghqqctwqlqrlqbdwfvjnhcpmzchqfrwzhzgslzhncmrlrpzcjczvzwcvwcldbmscfqnnqnwwvrpfvjswqmhgmhgnmfzpsjmdhbpvsftccttvdpcdzcnzswqmtrwbctpbgmzrvrrshjjgdqsqrwfpcmsbvqhccvjqpztlttwjjdtbmwslschpqjjllvjcjwtmrtvvwdzglstvtpndmmzcpgqsvqgfdtqdjdctsbsbmqzqhtczhgqgwbdlrhjrwcmtbzfndsbnpnhmsdhtghwwzvtdwtscdnwzmrjrsrjvvbvrpbszchwbltrjbcqmlhqnzcfbhjqnsjghlnlbsrgzrrzfvslwpbqmgfswhgjdsdfrzsdhvdqvqfbcbvmbfhjfpzwlbspcbnvrgpfnmjbwbsnpqpqhjpsnwrlcmfhpdmjbvpnctcfqgdmwzblsnr");
  EXPECT_EQ(startIndex, 1238);
}

TEST(TuningTroubleTest, SmallInputPart2) {
  int startIndex = DetectFirstStartOfPacketMarker("mjqjpqmgbljsphdztnvjfqwrcgsmlb", 14);
  EXPECT_EQ(startIndex, 19);
}

TEST(TuningTroubleTest, SmallInput2Part2) {
  int startIndex = DetectFirstStartOfPacketMarker("bvwbjplbgvbhsrlpgdmjqwftvncz", 14);
  EXPECT_EQ(startIndex, 23);
}

TEST(TuningTroubleTest, SmallInput3Part2) {
  int startIndex = DetectFirstStartOfPacketMarker("nppdvjthqldpwncqszvftbrmjlhg", 14);
  EXPECT_EQ(startIndex, 23);
}

TEST(TuningTroubleTest, SmallInput4Part2) {
  int startIndex = DetectFirstStartOfPacketMarker("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", 14);
  EXPECT_EQ(startIndex, 29);
}

TEST(TuningTroubleTest, SmallInput5Part2) {
  int startIndex = DetectFirstStartOfPacketMarker("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", 14);
  EXPECT_EQ(startIndex, 26);
}

TEST(TuningTroubleTest, Part2) {
  int startIndex = DetectFirstStartOfPacketMarker("dcbcsbblhhgdgssmcmqccdwdvwdvvcfvcfvvpvmmwccdqddshhdppcfpfbbfggfjfvvhzhmmsqswsttcgtctggjllhnnqbnnnldlglplvlbvbzztpzzvpphshwwfhhgssvgsvvpfvfzznbznndqqtsqttnvtvqqqrgqrrgzzlqzzbvzbzmzffnbfnbffcggdcggqhqpqzpqzqbbqvbqbhhtzhhrrrprlrclrcrssqspqpbblggfvvbpvbbssvttsztzpzjjwffnpnfnrrqhqgqrrzqzbzzdpdjpplpclpptltztjtztqthtmmmpsmmpjpqpvvshhsfshhrvrdvdggwssdbbzbttlmlmpprmrmlrrmqrqsshjhjljzjnjllbbvjvnnppqbppqqfffrbfbdfbbqppmtppfttqddtzzwbblqqbddgwgqwqzwwpzwzjjbccdjdwwrggrmrtmrtmrrvpptwwcdcwwsdshhjjhwjwqjwwqsshrrbsblssphspsjpssnsmsqswqwfwjwccdvccrqqnsqnsnwsnsmnmccvcqqfjjfljfljfjgjffjvffvjvhjhfhrfrlrrtpphbhwbbvmmnpndnlljdjfjsffvccnhchwhddrccljllmnnhmnmpnnhtnthnhvnhnwnqqjmmgzzvssphhjljbjwjbwwdnwwdvvzpvvhccvjjlclrrppgjgsshghvvzjvvpvvbjjqhjqqfcqffchcmmvdvtddftdtppfnppcnpnznwwpdpjpnpttlbbmmqfqmffqnfnbffbrbgbwggsmsbbfgbbfbzbtzbbvmmdlmlrlnlwwbswsjjpjhhwqwzqznqzqvvwccwvwwcbbpvvwcvcvzzhzchzccbnccjlljsjbjdbbvqbvvfdfgdfggzfzlzmzrznnqsnncmnnljjtcjcfftrthtrhrgrvvjggzpggrcrpcppggdfggpmmwnmnlmlglvvmjvvddsmsjsnjssqffffctczcjzjjlbbhpbbfdbdzbbsjbjnjbbqqjbqjbjjhwhssmvsschhhwppbjppllprpjrppdpfpgpjptjtptplpnptnptpjjmcmnnnhnjhjlhjlhjlhlwwhwmwjjbhhlfffrbbgvvqwvwswtstmmmfpmfpffmcfcrrqsqzqjjjnpnnztnznddlwdldsdbssstzstswwjtttmmwmsmwssvswszsjzsjjsffmccmfccqzzvpmbbbsqffgzdqbjtzhlqdzhlpwghlstcrcrffrnbwjnqgmbmpgttfmsswdqctlrpdnlsgnlldvbfpwtcptvbwftzcnbbscrrcpnwtmllcvsrmwzzlsdmfctdcwsqdlsnzgfpmzrnswhbqjhstztzzmzpcttsgsggnlhvjmcbbrhgqhsfmglpcbdvmmmnfbtbfrqbpcmttjtnwvznbshwrmznnsvpjqjntlzspljnbwtjcqztsfcqlrggrpzjgjsvqqcrmrjmzwdsshqfhbtfmlwmfvtbcgdmjgtcnphfmfmjlbjzrvjslccftnwcchgdwjnlthlwgldjwqwgdptdjdmzdrrzcdpbfrtdgcspjtqdqvzswwdwrhggdrqjjgwwrbwhhlrpqmszvlvjfqptncjlscvzbgzgmsttlbhbfrctnsphjcrcwlhcgrcrsjbrjvptgfbjgjrvtzmnhpzcgptbmrgvstsltnctjphsjdwpdqblfswzfhgjbpfrptlmhfwcpdlzqccgtdvbzhwngrhlqftmlhjprscflgzpflvvpfsjmlnmbzsrlrshvnsqrhhlqdlzhrcbjjjfrbqcdspwsmltcrtlbdnbnvhbbwgqdcncsztbfwztzdbqgcrnvndmpstpncbwvtctzdpmcpvrgqvjjztfwpvjtdqlvcvdpfzgcghsmbcwtzztmqwdpsprgsmfhphqsqmflrjdqzjscgzlnvcwcrlmpdscnhqpqjfdbdftqgttwntdbpnshdwnmwsrslfgnzlnwwwqgdbfnthhqtvbzsqgzjhhghtmvvfhlmlpbghnsvlttzsjlgndhdqmqqfdlqnbfscsnnqzcdwzdlqcnstcbsffghftqvwrsshgwmlnprhdnnwslwfwtmtfzdjwpmlvvdhjvdwrhvdsmpgrdpnqsjpqmhttrmdwllrmnbznwjwvvpjnnbnfzbdnhjbqqrnzgdqbspbqtwdpgsbwpzfdbpvzfjpsgmztnzrpvvhwlfscfvfpfblvplgdbhvjjpdjtnwrmvpjsphvglpsntvwtqwqvprcgwjltddpjngvmzfzhmqnnwglbzsbrcztpplpsmgmcfgzgpbtgsjrfvdzzcsthznvdpbwvdlcgdhncsjdvpcbbmtrqczctjljdfghsrvrsfjglqqhjttfdhqdqwhzhqrggsjwlldrntwmmbftgqjhpvvctpbtgltnttlhdqbsbwcqmctwlsnhmhncpmnzsllmjhcgnlfgvpcqrwzvsstgwbvjtnrlbblclzdrcwddrwnptqzgwdwtgrfwffpzjmwbqfmmrcfzfzjbwsslbhggtwtcrlhffzgfgrtljgnznnlgzwfmtwwqzhlthvpfclrtmrqfzrggbctzfsmjhrtwzpfrnhwwprnbwmvwvmvnzqpggmzgslctqbqdtvhgzjwzsnblqzmcpnpwllzhvzzmfqzfjlrsrcnjzqdzbpjftljtzvvmrjszvqllnhhgnrnqttnwlvllphjtnmlwqhcvmbsvnwtcdmhsmhdcwqwtvggcqfpdsrsscmhcvfzvdnffrfhdfmgbsghdbpwdwrdmlvsnzwcfchcqvccszdqrbnfvrpbftcwnjmczwgqzmtlmrthlhtjpmchltcmcqwgfgshtvtpmcmpbmlnjmhnpdsljjmjzddnlgtnjqztzsqqlhtqcscjvjncjvfcvsgjhqgzrmtjjcgvvmwswffmlcvlhqhbvrldrvbrfmmqcnqmfzlsghvclrdbsvcbqspgbzmjnlrdhvncnbcfmdlqrssggsmlwwglcjjzmcdwcnrgvvmgjcfbzlncmgqtllgldbdztbtfcjczqtjjlnpqmrgtjsmrbscvqlgqghfbgwccgwrjrzrsbbrqnjcqhllsqmrjtzmjnndwwmdjfhspjpgdcjjpdvwrsgjcfnpllnnnccvnfvqbpddgvbgbsbczmbzrbclczljdmbhpgmhwlqvnjzjwzzfjmsmcchjrqrtmhwlgjsptctlbtdnrqgntcvngcrqdqptfmhbvlhrqchdtwdwbrbqwtswzcrrfndldwmjbczppzrnncvvqsmpvvqcnsvhprhlmrhnjbwdvrbbwwdtmzrqttschrztgjcshlhfbmhmwrrmwgmfshpdhjwgdmcfdvqrmmwgmzbrlgbfltvlzmvqbgvhppdzglqbdlrhjnntnfvtmzjqccmqdbpjqphfggmjqdrndhclcfvqsjrsbcgdhcrbjsdjmwrzvpfpcjwjfdltztfzgmlzqzmztpvbflppgnhdzssznngfjggczdtdmcczjzfsnflpwqrbggmqdbbprfptzcdqvhrvszzjqqjlrlrdpwcnzhvgfhpcdbbgsfmtnszwbhwcdwdghqqctwqlqrlqbdwfvjnhcpmzchqfrwzhzgslzhncmrlrpzcjczvzwcvwcldbmscfqnnqnwwvrpfvjswqmhgmhgnmfzpsjmdhbpvsftccttvdpcdzcnzswqmtrwbctpbgmzrvrrshjjgdqsqrwfpcmsbvqhccvjqpztlttwjjdtbmwslschpqjjllvjcjwtmrtvvwdzglstvtpndmmzcpgqsvqgfdtqdjdctsbsbmqzqhtczhgqgwbdlrhjrwcmtbzfndsbnpnhmsdhtghwwzvtdwtscdnwzmrjrsrjvvbvrpbszchwbltrjbcqmlhqnzcfbhjqnsjghlnlbsrgzrrzfvslwpbqmgfswhgjdsdfrzsdhvdqvqfbcbvmbfhjfpzwlbspcbnvrgpfnmjbwbsnpqpqhjpsnwrlcmfhpdmjbvpnctcfqgdmwzblsnr", 14);
  EXPECT_EQ(startIndex, 3037);
}