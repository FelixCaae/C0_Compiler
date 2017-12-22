<program>
  <constDeclGroup>
  <keyword> const <\keyword>
    <constDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> cona <\identifier>
    <seperator> = <\seperator>
    <unsignedInt> 1 <\unsignedInt>
    <seperator> , <\seperator>
    <identifier> conb <\identifier>
    <seperator> = <\seperator>
    <unsignedInt> 2 <\unsignedInt>
    <\constDecl>
  <seperator> ; <\seperator>
  <keyword> const <\keyword>
    <constDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> conc <\identifier>
    <seperator> = <\seperator>
    <unsignedInt> 3 <\unsignedInt>
    <seperator> , <\seperator>
    <identifier> cong <\identifier>
    <seperator> = <\seperator>
    <unsignedInt> 4 <\unsignedInt>
    <\constDecl>
  <seperator> ; <\seperator>
  <keyword> const <\keyword>
    <constDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> conh <\identifier>
    <seperator> = <\seperator>
    <unsignedInt> 5 <\unsignedInt>
    <seperator> , <\seperator>
    <identifier> coni <\identifier>
    <seperator> = <\seperator>
    <unsignedInt> 6 <\unsignedInt>
    <seperator> , <\seperator>
    <identifier> conj <\identifier>
    <seperator> = <\seperator>
    <unsignedInt> 7 <\unsignedInt>
    <\constDecl>
  <seperator> ; <\seperator>
  <\constDeclGroup>
  <varDeclGroup>
    <varDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> a <\identifier>
    <seperator> [ <\seperator>
    <unsignedInt> 10 <\unsignedInt>
    <seperator> ] <\seperator>
    <\varDecl>
  <seperator> ; <\seperator>
    <varDecl>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> c <\identifier>
    <\varDecl>
  <seperator> ; <\seperator>
  <\varDeclGroup>
  <funcDecl>
  <keyword> void <\keyword>
  <identifier> emptyfunc <\identifier>
    <paramList>
    <seperator> ( <\seperator>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <statements>
      <\statements>
    <\compoundStatement>
  <seperator> } <\seperator>
  <\funcDecl>
  <funcDecl>
  <keyword> void <\keyword>
  <identifier> emptyfunc2 <\identifier>
    <paramList>
    <seperator> ( <\seperator>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <statements>
        <statement>
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
  <identifier> testchar <\identifier>
    <paramList>
    <seperator> ( <\seperator>
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
                <char> '0' <\char>
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
    <keyword> int <\keyword>
    <\type>
  <identifier> fibonacci <\identifier>
    <paramList>
    <seperator> ( <\seperator>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> n <\identifier>
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
        <identifier> cona <\identifier>
        <seperator> = <\seperator>
        <seperator> - <\seperator>
        <unsignedInt> 1 <\unsignedInt>
        <\constDecl>
      <seperator> ; <\seperator>
      <\constDeclGroup>
      <varDeclGroup>
        <varDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> testc <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
      <\varDeclGroup>
      <statements>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> n <\identifier>
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
                    <unsignedInt> 1 <\unsignedInt>
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
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> n <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> != <\seperator>
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
              <returnStat>
              <keyword> return <\keyword>
              <seperator> ( <\seperator>
                <expression>
                <seperator> + <\seperator>
                  <term>
                    <factor>
                    <identifier> fibonacci <\identifier>
                      <funCallStat>
                      <seperator> ( <\seperator>
                        <argumentList>
                          <expression>
                            <term>
                              <factor>
                              <identifier> n <\identifier>
                              <\factor>
                            <\term>
                          <seperator> + <\seperator>
                            <term>
                              <factor>
                              <seperator> - <\seperator>
                              <unsignedInt> 1 <\unsignedInt>
                              <\factor>
                            <\term>
                          <\expression>
                        <\argumentList>
                      <seperator> ) <\seperator>
                      <\funCallStat>
                    <\factor>
                  <\term>
                <seperator> + <\seperator>
                  <term>
                    <factor>
                    <identifier> fibonacci <\identifier>
                      <funCallStat>
                      <seperator> ( <\seperator>
                        <argumentList>
                          <expression>
                            <term>
                              <factor>
                              <identifier> n <\identifier>
                              <\factor>
                            <\term>
                          <seperator> - <\seperator>
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
                <seperator> + <\seperator>
                  <term>
                    <factor>
                    <unsignedInt> 0 <\unsignedInt>
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
          <returnStat>
          <keyword> return <\keyword>
          <seperator> ( <\seperator>
            <expression>
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
  <identifier> move <\identifier>
    <paramList>
    <seperator> ( <\seperator>
      <type>
      <keyword> char <\keyword>
      <\type>
    <identifier> a <\identifier>
    <seperator> , <\seperator>
      <type>
      <keyword> char <\keyword>
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
        <identifier> testcon1 <\identifier>
        <seperator> = <\seperator>
        <unsignedInt> 1 <\unsignedInt>
        <\constDecl>
      <seperator> ; <\seperator>
      <keyword> const <\keyword>
        <constDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> testcon2 <\identifier>
        <seperator> = <\seperator>
        <char> '1' <\char>
        <\constDecl>
      <seperator> ; <\seperator>
      <\constDeclGroup>
      <statements>
        <statement>
          <writeStat>
          <keyword> printf <\keyword>
          <seperator> ( <\seperator>
          <string> "MOVE" <\string>
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
                <identifier> a <\identifier>
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
          <string> " TO " <\string>
          <seperator> , <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> b <\identifier>
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
          <string> " " <\string>
          <seperator> ) <\seperator>
          <\writeStat>
        <seperator> ; <\seperator>
        <\statement>
      <\statements>
    <\compoundStatement>
  <seperator> } <\seperator>
  <\funcDecl>
  <funcDecl>
  <keyword> void <\keyword>
  <identifier> hanoi <\identifier>
    <paramList>
    <seperator> ( <\seperator>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> hano <\identifier>
    <seperator> , <\seperator>
      <type>
      <keyword> char <\keyword>
      <\type>
    <identifier> l <\identifier>
    <seperator> , <\seperator>
      <type>
      <keyword> char <\keyword>
      <\type>
    <identifier> m <\identifier>
    <seperator> , <\seperator>
      <type>
      <keyword> char <\keyword>
      <\type>
    <identifier> r <\identifier>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <statements>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <unsignedInt> 2 <\unsignedInt>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> > <\seperator>
              <\identifier>
              <expression>
                <term>
                  <factor>
                  <identifier> hano <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
            <statement>
            <seperator> { <\seperator>
              <statements>
                <statement>
                <identifier> move <\identifier>
                  <funCallStat>
                  <seperator> ( <\seperator>
                    <argumentList>
                      <expression>
                        <term>
                          <factor>
                          <identifier> l <\identifier>
                          <\factor>
                        <\term>
                      <\expression>
                    <seperator> , <\seperator>
                      <expression>
                        <term>
                          <factor>
                          <identifier> r <\identifier>
                          <\factor>
                        <\term>
                      <\expression>
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
                <statement>
                  <writeStat>
                  <keyword> printf <\keyword>
                  <seperator> ( <\seperator>
                  <string> "RETURN ERROR" <\string>
                  <seperator> ) <\seperator>
                  <\writeStat>
                <seperator> ; <\seperator>
                <\statement>
              <\statements>
            <seperator> } <\seperator>
            <\statement>
          <\constant>
        <\statement>
        <statement>
        <identifier> hanoi <\identifier>
          <funCallStat>
          <seperator> ( <\seperator>
            <argumentList>
              <expression>
                <term>
                  <factor>
                  <identifier> hano <\identifier>
                  <\factor>
                <\term>
              <seperator> - <\seperator>
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
                  <identifier> l <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <seperator> , <\seperator>
              <expression>
                <term>
                  <factor>
                  <identifier> r <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <seperator> , <\seperator>
              <expression>
                <term>
                  <factor>
                  <identifier> m <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <\argumentList>
          <seperator> ) <\seperator>
          <\funCallStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> move <\identifier>
          <funCallStat>
          <seperator> ( <\seperator>
            <argumentList>
              <expression>
                <term>
                  <factor>
                  <identifier> l <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <seperator> , <\seperator>
              <expression>
                <term>
                  <factor>
                  <identifier> r <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <\argumentList>
          <seperator> ) <\seperator>
          <\funCallStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> hanoi <\identifier>
          <funCallStat>
          <seperator> ( <\seperator>
            <argumentList>
              <expression>
                <term>
                  <factor>
                  <identifier> hano <\identifier>
                  <\factor>
                <\term>
              <seperator> - <\seperator>
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
                  <identifier> m <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <seperator> , <\seperator>
              <expression>
                <term>
                  <factor>
                  <identifier> l <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <seperator> , <\seperator>
              <expression>
                <term>
                  <factor>
                  <identifier> r <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <\argumentList>
          <seperator> ) <\seperator>
          <\funCallStat>
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
  <identifier> getpower <\identifier>
    <paramList>
    <seperator> ( <\seperator>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> n <\identifier>
    <seperator> , <\seperator>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> le <\identifier>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <varDeclGroup>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> move <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
      <\varDeclGroup>
      <statements>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> le <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> >= <\seperator>
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
                <identifier> move <\identifier>
                  <assignStat>
                  <seperator> = <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <identifier> getpower <\identifier>
                          <funCallStat>
                          <seperator> ( <\seperator>
                            <argumentList>
                              <expression>
                                <term>
                                  <factor>
                                  <identifier> n <\identifier>
                                  <\factor>
                                <\term>
                              <\expression>
                            <seperator> , <\seperator>
                              <expression>
                                <term>
                                  <factor>
                                  <identifier> le <\identifier>
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
                <identifier> a <\identifier>
                  <assignStat>
                  <seperator> [ <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <identifier> le <\identifier>
                        <\factor>
                      <\term>
                    <seperator> - <\seperator>
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
                        <identifier> move <\identifier>
                        <\factor>
                      <seperator> * <\seperator>
                        <factor>
                        <identifier> n <\identifier>
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
                        <identifier> n <\identifier>
                        <\factor>
                      <seperator> * <\seperator>
                        <factor>
                        <identifier> move <\identifier>
                        <\factor>
                      <\term>
                    <\expression>
                  <seperator> ) <\seperator>
                  <\returnStat>
                <seperator> ; <\seperator>
                <\statement>
              <\statements>
            <seperator> } <\seperator>
            <\statement>
          <\constant>
        <\statement>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <unsignedInt> 1 <\unsignedInt>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> <= <\seperator>
              <\identifier>
              <expression>
                <term>
                  <factor>
                  <identifier> le <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
            <statement>
            <seperator> { <\seperator>
              <statements>
                <statement>
                <identifier> a <\identifier>
                  <assignStat>
                  <seperator> [ <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <identifier> le <\identifier>
                        <\factor>
                      <\term>
                    <seperator> - <\seperator>
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
                        <identifier> n <\identifier>
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
                        <identifier> n <\identifier>
                        <\factor>
                      <\term>
                    <\expression>
                  <seperator> ) <\seperator>
                  <\returnStat>
                <seperator> ; <\seperator>
                <\statement>
              <\statements>
            <seperator> } <\seperator>
            <\statement>
          <\constant>
        <\statement>
      <\statements>
    <\compoundStatement>
  <seperator> } <\seperator>
  <\funcDecl>
  <funcDecl>
    <type>
    <keyword> int <\keyword>
    <\type>
  <identifier> getsqr <\identifier>
    <paramList>
    <seperator> ( <\seperator>
      <type>
      <keyword> int <\keyword>
      <\type>
    <identifier> n <\identifier>
    <seperator> ) <\seperator>
    <\paramList>
  <seperator> { <\seperator>
    <compoundStatement>
      <varDeclGroup>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> _i <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
      <\varDeclGroup>
      <statements>
        <statement>
        <identifier> _i <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 1 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <loopStat>
          <keyword> do <\keyword>
            <statement>
            <seperator> { <\seperator>
              <statements>
                <statement>
                <identifier> _i <\identifier>
                  <assignStat>
                  <seperator> = <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <identifier> _i <\identifier>
                        <\factor>
                      <\term>
                    <seperator> + <\seperator>
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
          <keyword> while <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
                <term>
                  <factor>
                  <identifier> _i <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> < <\seperator>
              <\identifier>
              <expression>
                <term>
                  <factor>
                  <identifier> n <\identifier>
                  <\factor>
                <seperator> / <\seperator>
                  <factor>
                  <identifier> _i <\identifier>
                  <\factor>
                <\term>
              <\expression>
            <\condition>
          <seperator> ) <\seperator>
          <\loopStat>
        <\statement>
        <statement>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <constant>
          <keyword> if <\keyword>
          <seperator> ( <\seperator>
            <condition>
              <expression>
              <seperator> - <\seperator>
                <term>
                  <factor>
                  <identifier> n <\identifier>
                  <\factor>
                <\term>
              <seperator> + <\seperator>
                <term>
                  <factor>
                  <identifier> _i <\identifier>
                  <\factor>
                <seperator> * <\seperator>
                  <factor>
                  <identifier> _i <\identifier>
                  <\factor>
                <\term>
              <\expression>
              <identifier>
              <seperator> < <\seperator>
              <\identifier>
              <expression>
                <term>
                  <factor>
                  <identifier> n <\identifier>
                  <\factor>
                <\term>
              <seperator> - <\seperator>
                <term>
                  <factor>
                  <seperator> ( <\seperator>
                    <expression>
                    <seperator> - <\seperator>
                      <term>
                        <factor>
                        <unsignedInt> 1 <\unsignedInt>
                        <\factor>
                      <\term>
                    <seperator> + <\seperator>
                      <term>
                        <factor>
                        <identifier> _i <\identifier>
                        <\factor>
                      <\term>
                    <\expression>
                  <seperator> ) <\seperator>
                  <\factor>
                <seperator> * <\seperator>
                  <factor>
                  <seperator> ( <\seperator>
                    <expression>
                      <term>
                        <factor>
                        <identifier> _i <\identifier>
                        <\factor>
                      <\term>
                    <seperator> - <\seperator>
                      <term>
                        <factor>
                        <unsignedInt> 1 <\unsignedInt>
                        <\factor>
                      <\term>
                    <\expression>
                  <seperator> ) <\seperator>
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
                    <identifier> _i <\identifier>
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
          <returnStat>
          <keyword> return <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> _i <\identifier>
                <\factor>
              <\term>
            <seperator> - <\seperator>
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
      <constDeclGroup>
      <keyword> const <\keyword>
        <constDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> cond <\identifier>
        <seperator> = <\seperator>
        <char> 'A' <\char>
        <seperator> , <\seperator>
        <identifier> cone <\identifier>
        <seperator> = <\seperator>
        <char> 'B' <\char>
        <seperator> , <\seperator>
        <identifier> conf <\identifier>
        <seperator> = <\seperator>
        <char> 'C' <\char>
        <\constDecl>
      <seperator> ; <\seperator>
      <keyword> const <\keyword>
        <constDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> con1 <\identifier>
        <seperator> = <\seperator>
        <char> '+' <\char>
        <seperator> , <\seperator>
        <identifier> con2 <\identifier>
        <seperator> = <\seperator>
        <char> '-' <\char>
        <\constDecl>
      <seperator> ; <\seperator>
      <keyword> const <\keyword>
        <constDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> con3 <\identifier>
        <seperator> = <\seperator>
        <char> '*' <\char>
        <\constDecl>
      <seperator> ; <\seperator>
      <keyword> const <\keyword>
        <constDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> ccon3 <\identifier>
        <seperator> = <\seperator>
        <char> '/' <\char>
        <\constDecl>
      <seperator> ; <\seperator>
      <keyword> const <\keyword>
        <constDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> testcon <\identifier>
        <seperator> = <\seperator>
        <unsignedInt> 100 <\unsignedInt>
        <\constDecl>
      <seperator> ; <\seperator>
      <\constDeclGroup>
      <varDeclGroup>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> tmp <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> c <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> num <\identifier>
        <seperator> , <\seperator>
        <identifier> i <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> fib <\identifier>
        <seperator> , <\seperator>
        <identifier> testaj <\identifier>
        <seperator> [ <\seperator>
        <unsignedInt> 10 <\unsignedInt>
        <seperator> ] <\seperator>
        <seperator> , <\seperator>
        <identifier> sqr <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> testai <\identifier>
        <seperator> [ <\seperator>
        <unsignedInt> 100 <\unsignedInt>
        <seperator> ] <\seperator>
        <seperator> , <\seperator>
        <identifier> a_ <\identifier>
        <seperator> , <\seperator>
        <identifier> a_a <\identifier>
        <seperator> , <\seperator>
        <identifier> a0 <\identifier>
        <seperator> , <\seperator>
        <identifier> a00 <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> testai1 <\identifier>
        <seperator> , <\seperator>
        <identifier> testai2 <\identifier>
        <seperator> , <\seperator>
        <identifier> testai3 <\identifier>
        <seperator> , <\seperator>
        <identifier> testai4 <\identifier>
        <seperator> , <\seperator>
        <identifier> testai5 <\identifier>
        <seperator> , <\seperator>
        <identifier> testai6 <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> c1 <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> c2 <\identifier>
        <seperator> , <\seperator>
        <identifier> c3 <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
        <varDecl>
          <type>
          <keyword> char <\keyword>
          <\type>
        <identifier> c4 <\identifier>
        <seperator> , <\seperator>
        <identifier> c5 <\identifier>
        <seperator> , <\seperator>
        <identifier> c6 <\identifier>
        <\varDecl>
      <seperator> ; <\seperator>
      <\varDeclGroup>
      <statements>
        <statement>
        <identifier> a_a <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 123456789 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> a_ <\identifier>
          <assignStat>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> cond <\identifier>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> testai <\identifier>
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
            <seperator> + <\seperator>
              <term>
                <factor>
                <unsignedInt> 5 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> testai <\identifier>
          <assignStat>
          <seperator> [ <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> testai <\identifier>
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
          <seperator> ] <\seperator>
          <seperator> = <\seperator>
            <expression>
              <term>
                <factor>
                <unsignedInt> 1 <\unsignedInt>
                <\factor>
              <\term>
            <\expression>
          <\assignStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
        <identifier> testai <\identifier>
          <assignStat>
          <seperator> [ <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> con1 <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ] <\seperator>
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
        <statement>
          <readStat>
          <keyword> scanf <\keyword>
          <seperator> ( <\seperator>
          <identifier> c <\identifier>
          <seperator> , <\seperator>
          <identifier> num <\identifier>
          <seperator> ) <\seperator>
          <\readStat>
        <seperator> ; <\seperator>
        <\statement>
        <statement>
          <switchStat>
          <keyword> switch <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> c <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <seperator> { <\seperator>
            <switchTable>
              <subSwitchStat>
              <keyword> case <\keyword>
                <constant>
                <unsignedInt> 1 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <seperator> { <\seperator>
                  <statements>
                    <statement>
                    <identifier> getpower <\identifier>
                      <funCallStat>
                      <seperator> ( <\seperator>
                        <argumentList>
                          <expression>
                            <term>
                              <factor>
                              <identifier> num <\identifier>
                              <\factor>
                            <\term>
                          <\expression>
                        <seperator> , <\seperator>
                          <expression>
                            <term>
                              <factor>
                              <unsignedInt> 10 <\unsignedInt>
                              <\factor>
                            <\term>
                          <\expression>
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
                            <unsignedInt> 0 <\unsignedInt>
                            <\factor>
                          <\term>
                        <\expression>
                      <\assignStat>
                    <seperator> ; <\seperator>
                    <\statement>
                    <statement>
                      <loopStat>
                      <keyword> do <\keyword>
                        <statement>
                        <seperator> { <\seperator>
                          <statements>
                            <statement>
                              <writeStat>
                              <keyword> printf <\keyword>
                              <seperator> ( <\seperator>
                              <string> "NO" <\string>
                              <seperator> , <\seperator>
                                <expression>
                                  <term>
                                    <factor>
                                    <identifier> i <\identifier>
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
                              <\writeStat>
                            <seperator> ; <\seperator>
                            <\statement>
                            <statement>
                              <writeStat>
                              <keyword> printf <\keyword>
                              <seperator> ( <\seperator>
                              <string> ":" <\string>
                              <seperator> , <\seperator>
                                <expression>
                                  <term>
                                    <factor>
                                    <identifier> a <\identifier>
                                    <seperator> [ <\seperator>
                                      <expression>
                                        <term>
                                          <factor>
                                          <identifier> i <\identifier>
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
                              <writeStat>
                              <keyword> printf <\keyword>
                              <seperator> ( <\seperator>
                              <string> " " <\string>
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
                            <identifier> i <\identifier>
                              <assignStat>
                              <seperator> = <\seperator>
                                <expression>
                                  <term>
                                    <factor>
                                    <identifier> i <\identifier>
                                    <\factor>
                                  <\term>
                                <seperator> + <\seperator>
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
                      <keyword> while <\keyword>
                      <seperator> ( <\seperator>
                        <condition>
                          <expression>
                            <term>
                              <factor>
                              <identifier> i <\identifier>
                              <\factor>
                            <\term>
                          <\expression>
                          <identifier>
                          <seperator> < <\seperator>
                          <\identifier>
                          <expression>
                            <term>
                              <factor>
                              <unsignedInt> 10 <\unsignedInt>
                              <\factor>
                            <\term>
                          <\expression>
                        <\condition>
                      <seperator> ) <\seperator>
                      <\loopStat>
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
          <switchStat>
          <keyword> switch <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> c <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <seperator> { <\seperator>
            <switchTable>
              <subSwitchStat>
              <keyword> case <\keyword>
                <constant>
                <seperator> + <\seperator>
                <unsignedInt> 2 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <identifier> hanoi <\identifier>
                  <funCallStat>
                  <seperator> ( <\seperator>
                    <argumentList>
                      <expression>
                        <term>
                          <factor>
                          <identifier> num <\identifier>
                          <\factor>
                        <\term>
                      <\expression>
                    <seperator> , <\seperator>
                      <expression>
                        <term>
                          <factor>
                          <identifier> cond <\identifier>
                          <\factor>
                        <\term>
                      <\expression>
                    <seperator> , <\seperator>
                      <expression>
                        <term>
                          <factor>
                          <identifier> cone <\identifier>
                          <\factor>
                        <\term>
                      <\expression>
                    <seperator> , <\seperator>
                      <expression>
                        <term>
                          <factor>
                          <identifier> conf <\identifier>
                          <\factor>
                        <\term>
                      <\expression>
                    <\argumentList>
                  <seperator> ) <\seperator>
                  <\funCallStat>
                <seperator> ; <\seperator>
                <\statement>
              <\subSwitchStat>
              <subSwitchStat>
              <keyword> case <\keyword>
                <constant>
                <unsignedInt> 3 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <seperator> { <\seperator>
                  <statements>
                    <statement>
                    <identifier> fib <\identifier>
                      <assignStat>
                      <seperator> = <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> fibonacci <\identifier>
                              <funCallStat>
                              <seperator> ( <\seperator>
                                <argumentList>
                                  <expression>
                                    <term>
                                      <factor>
                                      <identifier> num <\identifier>
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
                      <writeStat>
                      <keyword> printf <\keyword>
                      <seperator> ( <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> fib <\identifier>
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
          <switchStat>
          <keyword> switch <\keyword>
          <seperator> ( <\seperator>
            <expression>
              <term>
                <factor>
                <identifier> c <\identifier>
                <\factor>
              <\term>
            <\expression>
          <seperator> ) <\seperator>
          <seperator> { <\seperator>
            <switchTable>
              <subSwitchStat>
              <keyword> case <\keyword>
                <constant>
                <unsignedInt> 4 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <seperator> { <\seperator>
                  <statements>
                    <statement>
                    <identifier> sqr <\identifier>
                      <assignStat>
                      <seperator> = <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> getsqr <\identifier>
                              <funCallStat>
                              <seperator> ( <\seperator>
                                <argumentList>
                                  <expression>
                                    <term>
                                      <factor>
                                      <identifier> num <\identifier>
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
                      <writeStat>
                      <keyword> printf <\keyword>
                      <seperator> ( <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> sqr <\identifier>
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
                <unsignedInt> 5 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <seperator> { <\seperator>
                  <statements>
                    <statement>
                      <writeStat>
                      <keyword> printf <\keyword>
                      <seperator> ( <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> testchar <\identifier>
                              <funCallStat>
                              <seperator> ( <\seperator>
                                <argumentList>
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
                      <writeStat>
                      <keyword> printf <\keyword>
                      <seperator> ( <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <unsignedInt> 3 <\unsignedInt>
                            <\factor>
                          <seperator> * <\seperator>
                            <factor>
                            <unsignedInt> 2 <\unsignedInt>
                            <\factor>
                          <seperator> / <\seperator>
                            <factor>
                            <unsignedInt> 6 <\unsignedInt>
                            <\factor>
                          <seperator> * <\seperator>
                            <factor>
                            <identifier> testai <\identifier>
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
                  <\statements>
                <seperator> } <\seperator>
                <\statement>
              <\subSwitchStat>
              <subSwitchStat>
              <keyword> case <\keyword>
                <constant>
                <unsignedInt> 6 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <seperator> { <\seperator>
                  <statements>
                    <statement>
                      <constant>
                      <keyword> if <\keyword>
                      <seperator> ( <\seperator>
                        <condition>
                          <expression>
                            <term>
                              <factor>
                              <identifier> testai <\identifier>
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
                              <writeStat>
                              <keyword> printf <\keyword>
                              <seperator> ( <\seperator>
                              <string> "IFCORRECT" <\string>
                              <seperator> ) <\seperator>
                              <\writeStat>
                            <seperator> ; <\seperator>
                            <\statement>
                          <\statements>
                        <seperator> } <\seperator>
                        <\statement>
                      <\constant>
                    <\statement>
                    <statement>
                    <identifier> tmp <\identifier>
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
                      <loopStat>
                      <keyword> do <\keyword>
                        <statement>
                        <seperator> { <\seperator>
                          <statements>
                            <statement>
                              <writeStat>
                              <keyword> printf <\keyword>
                              <seperator> ( <\seperator>
                                <expression>
                                  <term>
                                    <factor>
                                    <identifier> testai <\identifier>
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
                            <identifier> testai <\identifier>
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
                                    <identifier> testai <\identifier>
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
                            <statement>
                            <identifier> tmp <\identifier>
                              <assignStat>
                              <seperator> = <\seperator>
                                <expression>
                                  <term>
                                    <factor>
                                    <identifier> tmp <\identifier>
                                    <\factor>
                                  <\term>
                                <seperator> + <\seperator>
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
                      <keyword> while <\keyword>
                      <seperator> ( <\seperator>
                        <condition>
                          <expression>
                            <term>
                              <factor>
                              <identifier> testai <\identifier>
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
                      <\loopStat>
                    <\statement>
                  <\statements>
                <seperator> } <\seperator>
                <\statement>
              <\subSwitchStat>
              <subSwitchStat>
              <keyword> case <\keyword>
                <constant>
                <seperator> - <\seperator>
                <unsignedInt> 7 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <seperator> { <\seperator>
                  <statements>
                    <statement>
                      <readStat>
                      <keyword> scanf <\keyword>
                      <seperator> ( <\seperator>
                      <identifier> testai1 <\identifier>
                      <seperator> ) <\seperator>
                      <\readStat>
                    <seperator> ; <\seperator>
                    <\statement>
                    <statement>
                      <readStat>
                      <keyword> scanf <\keyword>
                      <seperator> ( <\seperator>
                      <identifier> testai2 <\identifier>
                      <seperator> , <\seperator>
                      <identifier> testai3 <\identifier>
                      <seperator> ) <\seperator>
                      <\readStat>
                    <seperator> ; <\seperator>
                    <\statement>
                    <statement>
                      <readStat>
                      <keyword> scanf <\keyword>
                      <seperator> ( <\seperator>
                      <identifier> testai4 <\identifier>
                      <seperator> , <\seperator>
                      <identifier> testai5 <\identifier>
                      <seperator> , <\seperator>
                      <identifier> testai6 <\identifier>
                      <seperator> ) <\seperator>
                      <\readStat>
                    <seperator> ; <\seperator>
                    <\statement>
                    <statement>
                      <writeStat>
                      <keyword> printf <\keyword>
                      <seperator> ( <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> testai1 <\identifier>
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
                            <identifier> testai2 <\identifier>
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
                            <identifier> testai3 <\identifier>
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
                            <identifier> testai4 <\identifier>
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
                            <identifier> testai5 <\identifier>
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
                            <identifier> testai6 <\identifier>
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
                <unsignedInt> 0 <\unsignedInt>
                <\constant>
              <seperator> : <\seperator>
                <statement>
                <seperator> { <\seperator>
                  <statements>
                    <statement>
                      <readStat>
                      <keyword> scanf <\keyword>
                      <seperator> ( <\seperator>
                      <identifier> c1 <\identifier>
                      <seperator> ) <\seperator>
                      <\readStat>
                    <seperator> ; <\seperator>
                    <\statement>
                    <statement>
                      <switchStat>
                      <keyword> switch <\keyword>
                      <seperator> ( <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> c1 <\identifier>
                            <\factor>
                          <\term>
                        <\expression>
                      <seperator> ) <\seperator>
                      <seperator> { <\seperator>
                        <switchTable>
                          <subSwitchStat>
                          <keyword> case <\keyword>
                            <constant>
                            <char> 'a' <\char>
                            <\constant>
                          <seperator> : <\seperator>
                            <statement>
                              <writeStat>
                              <keyword> printf <\keyword>
                              <seperator> ( <\seperator>
                                <expression>
                                  <term>
                                    <factor>
                                    <unsignedInt> 1 <\unsignedInt>
                                    <\factor>
                                  <\term>
                                <\expression>
                              <seperator> ) <\seperator>
                              <\writeStat>
                            <seperator> ; <\seperator>
                            <\statement>
                          <\subSwitchStat>
                          <subSwitchStat>
                          <keyword> case <\keyword>
                            <constant>
                            <char> 'b' <\char>
                            <\constant>
                          <seperator> : <\seperator>
                            <statement>
                              <writeStat>
                              <keyword> printf <\keyword>
                              <seperator> ( <\seperator>
                                <expression>
                                  <term>
                                    <factor>
                                    <unsignedInt> 2 <\unsignedInt>
                                    <\factor>
                                  <\term>
                                <\expression>
                              <seperator> ) <\seperator>
                              <\writeStat>
                            <seperator> ; <\seperator>
                            <\statement>
                          <\subSwitchStat>
                        <\switchTable>
                      <seperator> } <\seperator>
                      <\switchStat>
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
