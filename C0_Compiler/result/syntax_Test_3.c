<program>
  <constDeclGroup>
  <keyword> const <\keyword>
    <constDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> cint1 <\identifier>
    <seperator> = <\seperator>
    <seperator> + <\seperator>
    <unsignedInt> 10 <\unsignedInt>
    <seperator> , <\seperator>
    <identifier> cint2 <\identifier>
    <seperator> = <\seperator>
    <seperator> - <\seperator>
    <unsignedInt> 1 <\unsignedInt>
    <\constDecl>
  <seperator> ; <\seperator>
  <keyword> const <\keyword>
    <constDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> cint3 <\identifier>
    <seperator> = <\seperator>
    <unsignedInt> 0 <\unsignedInt>
    <\constDecl>
  <seperator> ; <\seperator>
  <keyword> const <\keyword>
    <constDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> cmaxint <\identifier>
    <seperator> = <\seperator>
    <unsignedInt> 2147483647 <\unsignedInt>
    <seperator> , <\seperator>
    <identifier> cminint <\identifier>
    <seperator> = <\seperator>
    <seperator> - <\seperator>
    <unsignedInt> 2147483648 <\unsignedInt>
    <\constDecl>
  <seperator> ; <\seperator>
  <keyword> const <\keyword>
    <constDecl>
      <type>
      <keyword> char <\keyword>
      <\type>
    <identifier> cchar0 <\identifier>
    <seperator> = <\seperator>
    <char> '_' <\char>
    <seperator> , <\seperator>
    <identifier> cchar1 <\identifier>
    <seperator> = <\seperator>
    <char> 'a' <\char>
    <seperator> , <\seperator>
    <identifier> cchar2 <\identifier>
    <seperator> = <\seperator>
    <char> 'A' <\char>
    <seperator> , <\seperator>
    <identifier> cchar3 <\identifier>
    <seperator> = <\seperator>
    <char> '+' <\char>
    <seperator> , <\seperator>
    <identifier> cchar4 <\identifier>
    <seperator> = <\seperator>
    <char> '*' <\char>
    <\constDecl>
  <seperator> ; <\seperator>
  <keyword> const <\keyword>
    <constDecl>
      <type>
      <keyword> char <\keyword>
      <\type>
    <identifier> cchar5 <\identifier>
    <seperator> = <\seperator>
    <char> '0' <\char>
    <\constDecl>
  <seperator> ; <\seperator>
  <\constDeclGroup>
  <varDeclGroup>
    <varDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> _ <\identifier>
    <seperator> , <\seperator>
    <identifier> _9 <\identifier>
    <seperator> , <\seperator>
    <identifier> __ <\identifier>
    <seperator> , <\seperator>
    <identifier> _a <\identifier>
    <\varDecl>
  <seperator> ; <\seperator>
    <varDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> a1 <\identifier>
    <\varDecl>
  <seperator> ; <\seperator>
    <varDecl>
      <type>
      <keyword> char <\keyword>
      <\type>
    <identifier> ___a <\identifier>
    <\varDecl>
  <seperator> ; <\seperator>
    <varDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> a2 <\identifier>
    <seperator> , <\seperator>
    <identifier> a3 <\identifier>
    <seperator> [ <\seperator>
    <unsignedInt> 10 <\unsignedInt>
    <seperator> ] <\seperator>
    <seperator> , <\seperator>
    <identifier> a4 <\identifier>
    <seperator> [ <\seperator>
    <unsignedInt> 1 <\unsignedInt>
    <seperator> ] <\seperator>
    <seperator> , <\seperator>
    <identifier> a5 <\identifier>
    <\varDecl>
  <seperator> ; <\seperator>
    <varDecl>
      <type>
      <keyword> char <\keyword>
      <\type>
    <identifier> aa2 <\identifier>
    <seperator> [ <\seperator>
    <unsignedInt> 1 <\unsignedInt>
    <seperator> ] <\seperator>
    <seperator> , <\seperator>
    <identifier> aa3 <\identifier>
    <seperator> [ <\seperator>
    <unsignedInt> 20 <\unsignedInt>
    <seperator> ] <\seperator>
    <seperator> , <\seperator>
    <identifier> aa4 <\identifier>
    <\varDecl>
  <seperator> ; <\seperator>
  <\varDeclGroup>
  <funcDecl>
  <keyword> void <\keyword>
  <identifier> printhelloworld <\identifier>
    <paramList>
    <seperator> ( <\seperator>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <varDeclGroup>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> cint2 <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
      <\varDeclGroup>
      <statements>
        <statement>
        <identifier> cint2 <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 233 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> " !#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~" <\string>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "" <\string>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "helloworld!" <\string>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <char> '+' <\char>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <char> '-' <\char>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <char> '*' <\char>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <char> '/' <\char>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> cchar0 <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> cint1 <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> cint2 <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <returnStat>
          <keyword> return <\keyword>
          <\returnStat>
        <seperator> ; <\seperator>
        <\statement>
      <\statements>
    <\compoundStatement>
  <seperator> } <\seperator>
  <\funcDecl>
  <funcDecl>
    <type>
    <keyword> int <\keyword>
    <\type>
  <identifier> squaresum <\identifier>
    <paramList>
    <seperator> ( <\seperator>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> _a <\identifier>
    <seperator> , <\seperator>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> b <\identifier>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <constDeclGroup>
      <keyword> const <\keyword>
        <constDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> unuse <\identifier>
        <seperator> = <\seperator>
        <unsignedInt> 0 <\unsignedInt>
        <\constDecl>
      <seperator> ; <\seperator>
      <\constDeclGroup>
      <varDeclGroup>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> temp <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
      <\varDeclGroup>
      <statements>
        <statement>
        <identifier> temp <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
            <seperator> - <\seperator>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <seperator> * <\seperator>
                <factor>
                <seperator> - <\seperator>
                <unsignedInt> 1 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> temp <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
            <seperator> + <\seperator>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <seperator> * <\seperator>
                <factor>
                <unsignedInt> 0 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> temp <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <seperator> * <\seperator>
                <factor>
                <identifier> unuse <\identifier>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> temp <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <seperator> * <\seperator>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> temp <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
            <seperator> - <\seperator>
              <term>
                <factor>
                <seperator> ( <\seperator>
                  <expression>
                  <seperator> - <\seperator>
                    <term>
                      <factor>
                      <identifier> _a <\identifier>
                      <\factor>
                    <seperator> * <\seperator>
                      <factor>
                      <identifier> _a <\identifier>
                      <\factor>
                    <\term>
                  <\expression>
                <seperator> ) <\seperator>
                <\factor>
              <\term>
            <seperator> + <\seperator>
              <term>
                <factor>
                <seperator> ( <\seperator>
                  <expression>
                    <term>
                      <factor>
                      <identifier> b <\identifier>
                      <\factor>
                    <seperator> * <\seperator>
                      <factor>
                      <identifier> b <\identifier>
                      <\factor>
                    <\term>
                  <\expression>
                <seperator> ) <\seperator>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <returnStat>
          <keyword> return <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> temp <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\returnStat>
        <seperator> ; <\seperator>
        <\statement>
      <\statements>
    <\compoundStatement>
  <seperator> } <\seperator>
  <\funcDecl>
  <funcDecl>
  <keyword> void <\keyword>
  <identifier> _mystop <\identifier>
    <paramList>
    <seperator> ( <\seperator>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <varDeclGroup>
        <varDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> temp <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
      <\varDeclGroup>
      <statements>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "input a char and enter:" <\string>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <readStat>
          <keyword> scanf <\keyword>
          <seperator> ( <\seperator>
          <identifier> temp <\identifier>
          <seperator> ) <\seperator>
          <\readStat>
        <seperator> ; <\seperator>
        <\statement>
      <\statements>
    <\compoundStatement>
  <seperator> } <\seperator>
  <\funcDecl>
  <funcDecl>
    <type>
    <keyword> int <\keyword>
    <\type>
  <identifier> nsquaresum <\identifier>
    <paramList>
    <seperator> ( <\seperator>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> temp <\identifier>
    <seperator> , <\seperator>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> times <\identifier>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <varDeclGroup>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> noneuse <\identifier>
        <seperator> [ <\seperator>
        <unsignedInt> 10 <\unsignedInt>
        <seperator> ] <\seperator>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> ttemp <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
      <\varDeclGroup>
      <statements>
        <statement>
        <identifier> ttemp <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> temp <\identifier>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> times <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> == <\seperator>
              <\identifier>
              <expression>
                <term>
                  <factor>
                  <unsignedInt> 1 <\unsignedInt>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
            <statement>
              <returnStat>
              <keyword> return <\keyword>
              <seperator> ( <\seperator>
                <expression>
                  <term>
                    <factor>
                    <identifier> temp <\identifier>
                    <\factor>
                  <\term>
                <\expression>
              <seperator> ) <\seperator>
              <\returnStat>
            <seperator> ; <\seperator>
            <\statement>
          <\constant>
        <\statement>
        <statement>
        <identifier> ttemp <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> ttemp <\identifier>
                <\factor>
              <seperator> * <\seperator>
                <factor>
                <identifier> nsquaresum <\identifier>
                  <funCallStat>
                  <seperator> ( <\seperator>
                    <argumentList>
                      <expression>
                        <term>
                          <factor>
                          <identifier> temp <\identifier>
                          <\factor>
                        <\term>
                      <\expression>
                    <seperator> , <\seperator>
                      <expression>
                        <term>
                          <factor>
                          <identifier> times <\identifier>
                          <\factor>
                        <\term>
                      <seperator> - <\seperator>
                        <term>
                          <factor>
                          <unsignedInt> 1 <\unsignedInt>
                          <\factor>
                        <\term>
                      <\expression>
                    <\argumentList>
                  <seperator> ) <\seperator>
                  <\funCallStat>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <returnStat>
          <keyword> return <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <seperator> ( <\seperator>
                  <expression>
                    <term>
                      <factor>
                      <seperator> ( <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> ttemp <\identifier>
                            <\factor>
                          <\term>
                        <\expression>
                      <seperator> ) <\seperator>
                      <\factor>
                    <\term>
                  <\expression>
                <seperator> ) <\seperator>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\returnStat>
        <seperator> ; <\seperator>
        <\statement>
      <\statements>
    <\compoundStatement>
  <seperator> } <\seperator>
  <\funcDecl>
  <funcDecl>
    <type>
    <keyword> char <\keyword>
    <\type>
  <identifier> nextalphabet <\identifier>
    <paramList>
    <seperator> ( <\seperator>
      <type>
      <keyword> char <\keyword>
      <\type>
    <identifier> x <\identifier>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <statements>
        <statement>
          <returnStat>
          <keyword> return <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> x <\identifier>
                <\factor>
              <\term>
            <seperator> + <\seperator>
              <term>
                <factor>
                <unsignedInt> 1 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\returnStat>
        <seperator> ; <\seperator>
        <\statement>
      <\statements>
    <\compoundStatement>
  <seperator> } <\seperator>
  <\funcDecl>
  <funcDecl>
  <keyword> void <\keyword>
  <keyword> main <\keyword>
    <paramList>
    <seperator> ( <\seperator>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <varDeclGroup>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> num <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> temp1 <\identifier>
        <seperator> , <\seperator>
        <identifier> temp2 <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> abc <\identifier>
        <seperator> [ <\seperator>
        <unsignedInt> 3 <\unsignedInt>
        <seperator> ] <\seperator>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> intarray <\identifier>
        <seperator> [ <\seperator>
        <unsignedInt> 1 <\unsignedInt>
        <seperator> ] <\seperator>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> i <\identifier>
        <seperator> , <\seperator>
        <identifier> j <\identifier>
        <seperator> , <\seperator>
        <identifier> k <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
      <\varDeclGroup>
      <statements>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "MaxInt" <\string>
          <seperator> , <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> cmaxint <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "MinInt" <\string>
          <seperator> , <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> cminint <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> printhelloworld <\identifier>
          <funCallStat>
          <seperator> ( <\seperator>
            <argumentList>
            <\argumentList>
          <seperator> ) <\seperator>
          <\funCallStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "please input number counts:" <\string>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <readStat>
          <keyword> scanf <\keyword>
          <seperator> ( <\seperator>
          <identifier> num <\identifier>
          <seperator> ) <\seperator>
          <\readStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> i <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 0 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> _a <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 666 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> intarray <\identifier>
          <assignStat>
          <seperator> [ <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 0 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <seperator> ] <\seperator>
          <seperator> = <\seperator>
            <expression>
            <seperator> - <\seperator>
              <term>
                <factor>
                <unsignedInt> 20 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> intarray <\identifier>
                <seperator> [ <\seperator>
                  <expression>
                    <term>
                      <factor>
                      <unsignedInt> 0 <\unsignedInt>
                      <\factor>
                    <\term>
                  <\expression>
                <seperator> ] <\seperator>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> abc <\identifier>
          <assignStat>
          <seperator> [ <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 0 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <seperator> ] <\seperator>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <char> 'a' <\char>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> abc <\identifier>
          <assignStat>
          <seperator> [ <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 1 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <seperator> ] <\seperator>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <char> 'b' <\char>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> abc <\identifier>
          <assignStat>
          <seperator> [ <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 2 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <seperator> ] <\seperator>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <char> 'c' <\char>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> nextalphabet <\identifier>
                  <funCallStat>
                  <seperator> ( <\seperator>
                    <argumentList>
                      <expression>
                        <term>
                          <factor>
                          <identifier> abc <\identifier>
                          <seperator> [ <\seperator>
                            <expression>
                              <term>
                                <factor>
                                <unsignedInt> 0 <\unsignedInt>
                                <\factor>
                              <\term>
                            <\expression>
                          <seperator> ] <\seperator>
                          <\factor>
                        <\term>
                      <\expression>
                    <\argumentList>
                  <seperator> ) <\seperator>
                  <\funCallStat>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> _a <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> > <\seperator>
              <\identifier>
              <expression>
                <term>
                  <factor>
                  <identifier> intarray <\identifier>
                  <seperator> [ <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <unsignedInt> 0 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <seperator> ] <\seperator>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
            <statement>
            <seperator> { <\seperator>
              <statements>
                <statement>
                <identifier> _a <\identifier>
                  <assignStat>
                  <seperator> = <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <identifier> intarray <\identifier>
                        <seperator> [ <\seperator>
                          <expression>
                            <term>
                              <factor>
                              <unsignedInt> 0 <\unsignedInt>
                              <\factor>
                            <\term>
                          <\expression>
                        <seperator> ] <\seperator>
                        <\factor>
                      <\term>
                    <seperator> - <\seperator>
                      <term>
                        <factor>
                        <unsignedInt> 1 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <\assignStat>
                <seperator> ; <\seperator>
                <\statement>
              <\statements>
            <seperator> } <\seperator>
            <\statement>
          <\constant>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "_a is" <\string>
          <seperator> , <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> _a <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> < <\seperator>
              <\identifier>
              <expression>
                <term>
                  <factor>
                  <identifier> intarray <\identifier>
                  <seperator> [ <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <unsignedInt> 0 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <seperator> ] <\seperator>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
            <statement>
            <seperator> { <\seperator>
              <statements>
                <statement>
                <identifier> _a <\identifier>
                  <assignStat>
                  <seperator> = <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <unsignedInt> 2 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <\assignStat>
                <seperator> ; <\seperator>
                <\statement>
              <\statements>
            <seperator> } <\seperator>
            <\statement>
          <\constant>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "_a is" <\string>
          <seperator> , <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> _a <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> == <\seperator>
              <\identifier>
              <expression>
                <term>
                  <factor>
                  <unsignedInt> 2 <\unsignedInt>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
            <statement>
            <seperator> { <\seperator>
              <statements>
                <statement>
                <identifier> _a <\identifier>
                  <assignStat>
                  <seperator> = <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <identifier> intarray <\identifier>
                        <seperator> [ <\seperator>
                          <expression>
                            <term>
                              <factor>
                              <unsignedInt> 0 <\unsignedInt>
                              <\factor>
                            <\term>
                          <\expression>
                        <seperator> ] <\seperator>
                        <\factor>
                      <seperator> * <\seperator>
                        <factor>
                        <unsignedInt> 2 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <\assignStat>
                <seperator> ; <\seperator>
                <\statement>
              <\statements>
            <seperator> } <\seperator>
            <\statement>
          <\constant>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "_a is" <\string>
          <seperator> , <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> _a <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> != <\seperator>
              <\identifier>
              <expression>
                <term>
                  <factor>
                  <identifier> intarray <\identifier>
                  <seperator> [ <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <unsignedInt> 0 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <seperator> ] <\seperator>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
            <statement>
            <seperator> { <\seperator>
              <statements>
                <statement>
                <identifier> _a <\identifier>
                  <assignStat>
                  <seperator> = <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <unsignedInt> 4 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <\assignStat>
                <seperator> ; <\seperator>
                <\statement>
              <\statements>
            <seperator> } <\seperator>
            <\statement>
          <\constant>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "_a is" <\string>
          <seperator> , <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> _a <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> >= <\seperator>
              <\identifier>
              <expression>
              <seperator> + <\seperator>
                <term>
                  <factor>
                  <unsignedInt> 4 <\unsignedInt>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
            <statement>
            <seperator> { <\seperator>
              <statements>
                <statement>
                <identifier> _a <\identifier>
                  <assignStat>
                  <seperator> = <\seperator>
                    <expression>
                    <seperator> - <\seperator>
                      <term>
                        <factor>
                        <unsignedInt> 0 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <\assignStat>
                <seperator> ; <\seperator>
                <\statement>
              <\statements>
            <seperator> } <\seperator>
            <\statement>
          <\constant>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "_a is" <\string>
          <seperator> , <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> _a <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> <= <\seperator>
              <\identifier>
              <expression>
              <seperator> + <\seperator>
                <term>
                  <factor>
                  <unsignedInt> 0 <\unsignedInt>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
            <statement>
            <seperator> { <\seperator>
              <statements>
                <statement>
                  <writeStat>
                  <keyword> printf <\keyword>
                  <seperator> ( <\seperator>
                  <string> "if ok....perhaps" <\string>
                  <seperator> , <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <identifier> _a <\identifier>
                        <\factor>
                      <\term>
                    <\expression>
                  <seperator> ) <\seperator>
                  <\writeStat>
                <seperator> ; <\seperator>
                <\statement>
                <statement>
                <identifier> _a <\identifier>
                  <assignStat>
                  <seperator> = <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <unsignedInt> 666 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <\assignStat>
                <seperator> ; <\seperator>
                <\statement>
              <\statements>
            <seperator> } <\seperator>
            <\statement>
          <\constant>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "_a is" <\string>
          <seperator> , <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> _a <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <switchStat>
          <keyword> switch <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> num <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <seperator> { <\seperator>
            <switchTable>
              <subSwitchStat>
              <keyword> case <\keyword>
                <constant>
                <unsignedInt> 0 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                  <writeStat>
                  <keyword> printf <\keyword>
                  <seperator> ( <\seperator>
                  <string> "result:0" <\string>
                  <seperator> ) <\seperator>
                  <\writeStat>
                <seperator> ; <\seperator>
                <\statement>
              <\subSwitchStat>
              <subSwitchStat>
              <keyword> case <\keyword>
                <constant>
                <seperator> + <\seperator>
                <unsignedInt> 1 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <seperator> { <\seperator>
                  <statements>
                    <statement>
                      <readStat>
                      <keyword> scanf <\keyword>
                      <seperator> ( <\seperator>
                      <identifier> temp1 <\identifier>
                      <seperator> ) <\seperator>
                      <\readStat>
                    <seperator> ; <\seperator>
                    <\statement>
                    <statement>
                      <writeStat>
                      <keyword> printf <\keyword>
                      <seperator> ( <\seperator>
                      <string> "result:" <\string>
                      <seperator> , <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> temp1 <\identifier>
                            <\factor>
                          <\term>
                        <seperator> + <\seperator>
                          <term>
                            <factor>
                            <unsignedInt> 10 <\unsignedInt>
                            <\factor>
                          <\term>
                        <seperator> - <\seperator>
                          <term>
                            <factor>
                            <unsignedInt> 10 <\unsignedInt>
                            <\factor>
                          <\term>
                        <\expression>
                      <seperator> ) <\seperator>
                      <\writeStat>
                    <seperator> ; <\seperator>
                    <\statement>
                  <\statements>
                <seperator> } <\seperator>
                <\statement>
              <\subSwitchStat>
              <subSwitchStat>
              <keyword> case <\keyword>
                <constant>
                <seperator> + <\seperator>
                <unsignedInt> 2 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <seperator> { <\seperator>
                  <statements>
                    <statement>
                      <readStat>
                      <keyword> scanf <\keyword>
                      <seperator> ( <\seperator>
                      <identifier> temp1 <\identifier>
                      <seperator> , <\seperator>
                      <identifier> temp2 <\identifier>
                      <seperator> ) <\seperator>
                      <\readStat>
                    <seperator> ; <\seperator>
                    <\statement>
                    <statement>
                      <writeStat>
                      <keyword> printf <\keyword>
                      <seperator> ( <\seperator>
                      <string> "result:" <\string>
                      <seperator> , <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> squaresum <\identifier>
                              <funCallStat>
                              <seperator> ( <\seperator>
                                <argumentList>
                                  <expression>
                                    <term>
                                      <factor>
                                      <identifier> temp1 <\identifier>
                                      <\factor>
                                    <\term>
                                  <seperator> + <\seperator>
                                    <term>
                                      <factor>
                                      <unsignedInt> 0 <\unsignedInt>
                                      <\factor>
                                    <\term>
                                  <\expression>
                                <seperator> , <\seperator>
                                  <expression>
                                    <term>
                                      <factor>
                                      <identifier> temp2 <\identifier>
                                      <\factor>
                                    <\term>
                                  <seperator> - <\seperator>
                                    <term>
                                      <factor>
                                      <unsignedInt> 2 <\unsignedInt>
                                      <\factor>
                                    <\term>
                                  <seperator> + <\seperator>
                                    <term>
                                      <factor>
                                      <unsignedInt> 2 <\unsignedInt>
                                      <\factor>
                                    <\term>
                                  <\expression>
                                <\argumentList>
                              <seperator> ) <\seperator>
                              <\funCallStat>
                            <\factor>
                          <\term>
                        <\expression>
                      <seperator> ) <\seperator>
                      <\writeStat>
                    <seperator> ; <\seperator>
                    <\statement>
                  <\statements>
                <seperator> } <\seperator>
                <\statement>
              <\subSwitchStat>
            <\switchTable>
          <seperator> } <\seperator>
          <\switchStat>
        <\statement>
        <statement>
        <identifier> _mystop <\identifier>
          <funCallStat>
          <seperator> ( <\seperator>
            <argumentList>
            <\argumentList>
          <seperator> ) <\seperator>
          <\funCallStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> i <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <seperator> ( <\seperator>
                  <expression>
                    <term>
                      <factor>
                      <identifier> nsquaresum <\identifier>
                        <funCallStat>
                        <seperator> ( <\seperator>
                          <argumentList>
                            <expression>
                              <term>
                                <factor>
                                <unsignedInt> 1 <\unsignedInt>
                                <\factor>
                              <\term>
                            <\expression>
                          <seperator> , <\seperator>
                            <expression>
                              <term>
                                <factor>
                                <unsignedInt> 1 <\unsignedInt>
                                <\factor>
                              <\term>
                            <\expression>
                          <\argumentList>
                        <seperator> ) <\seperator>
                        <\funCallStat>
                      <\factor>
                    <\term>
                  <\expression>
                <seperator> ) <\seperator>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "" <\string>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> k <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> temp1 <\identifier>
                <\factor>
              <\term>
            <seperator> + <\seperator>
              <term>
                <factor>
                <identifier> temp2 <\identifier>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> i <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> temp1 <\identifier>
                <\factor>
              <\term>
            <seperator> + <\seperator>
              <term>
                <factor>
                <identifier> temp2 <\identifier>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> j <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> temp1 <\identifier>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> j <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> j <\identifier>
                <\factor>
              <\term>
            <seperator> + <\seperator>
              <term>
                <factor>
                <identifier> temp2 <\identifier>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> _mystop <\identifier>
          <funCallStat>
          <seperator> ( <\seperator>
            <argumentList>
            <\argumentList>
          <seperator> ) <\seperator>
          <\funCallStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <returnStat>
          <keyword> return <\keyword>
          <\returnStat>
        <seperator> ; <\seperator>
        <\statement>
      <\statements>
    <\compoundStatement>
  <seperator> } <\seperator>
  <\funcDecl>
<\program>
<end> ÿ <\end>
