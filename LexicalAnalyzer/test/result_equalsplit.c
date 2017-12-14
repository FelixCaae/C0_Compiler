<program>
  <constDeclGroup>
  <keyword> const <\keyword>
    <constDecl>
    <keyword> int <\keyword>
    <identifier> MaxN <\identifier>
    <seperator> = <\seperator>
      <unsignedInt>
      <unsignedInt> 100 <\unsignedInt>
      <\unsignedInt>
    <\constDecl>
  <seperator> ; <\seperator>
  <\constDeclGroup>
  <varDeclGroup>
    <varDecl>
    <keyword> int <\keyword>
    <identifier> n <\identifier>
    <\varDecl>
  <seperator> ; <\seperator>
    <varDecl>
    <keyword> int <\keyword>
    <identifier> s <\identifier>
    <\varDecl>
  <seperator> ; <\seperator>
    <varDecl>
    <keyword> int <\keyword>
    <identifier> i <\identifier>
    <seperator> , <\seperator>
    <identifier> j <\identifier>
    <\varDecl>
  <seperator> ; <\seperator>
    <varDecl>
    <keyword> int <\keyword>
    <identifier> dyn <\identifier>
    <seperator> [ <\seperator>
    <unsignedInt> 5050 <\unsignedInt>
    <seperator> ] <\seperator>
    <\varDecl>
  <seperator> ; <\seperator>
    <varDecl>
    <keyword> int <\keyword>
    <identifier> Mod <\identifier>
      <funcDecl>
        <type>
        <keyword> int <\keyword>
        <\type>
      <seperator> Mod <\seperator>
        <paramList>
        <seperator> ( <\seperator>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> a <\identifier>
        <seperator> , <\seperator>
          <type>
          <keyword> int <\keyword>
          <\type>
        <identifier> b <\identifier>
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
                      <identifier> a <\identifier>
                      <\factor>
                    <\term>
                  <\expression>
                <seperator> < <\seperator>
                  <expression>
                    <term>
                      <factor>
                        <unsignedInt>
                        <unsignedInt> 0 <\unsignedInt>
                        <\unsignedInt>
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
                        <identifier> a <\identifier>
                        <\factor>
                      <\term>
                    <seperator> + <\seperator>
                      <term>
                        <factor>
                        <identifier> b <\identifier>
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
                    <identifier> Mod <\identifier>
                    <seperator> ( <\seperator>
                      <argumentList>
                        <expression>
                          <term>
                            <factor>
                            <identifier> a <\identifier>
                            <\factor>
                          <\term>
                        <seperator> - <\seperator>
                          <term>
                            <factor>
                            <identifier> b <\identifier>
                            <\factor>
                          <\term>
                        <\expression>
                      <seperator> , <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> b <\identifier>
                            <\factor>
                          <\term>
                        <\expression>
                      <\argumentList>
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
      <keyword> void <\keyword>
      <keyword> main <\keyword>
      <seperator> ( <\seperator>
      <seperator> ) <\seperator>
      <seperator> { <\seperator>
        <compoundStatement>
          <statements>
            <statement>
              <readStat>
              <keyword> scanf <\keyword>
              <seperator> ( <\seperator>
              <identifier> n <\identifier>
              <seperator> ) <\seperator>
              <\readStat>
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
                      <identifier> n <\identifier>
                      <\factor>
                    <\term>
                  <\expression>
                <seperator> < <\seperator>
                  <expression>
                    <term>
                      <factor>
                        <unsignedInt>
                        <unsignedInt> 0 <\unsignedInt>
                        <\unsignedInt>
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
                      <string> "n should be bigger or equal to zero" <\string>
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
                <seperator> > <\seperator>
                  <expression>
                    <term>
                      <factor>
                      <identifier> MaxN <\identifier>
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
                      <string> "n should be less or equal than" <\string>
                      <seperator> , <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> MaxN <\identifier>
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
              <\constant>
            <\statement>
            <statement>
            <identifier> s <\identifier>
              <assignStat>
              <seperator> = <\seperator>
                <expression>
                  <term>
                    <factor>
                    <identifier> n <\identifier>
                    <\factor>
                  <seperator> * <\seperator>
                    <factor>
                    <seperator> ( <\seperator>
                      <expression>
                        <term>
                          <factor>
                          <identifier> n <\identifier>
                          <\factor>
                        <\term>
                      <seperator> + <\seperator>
                        <term>
                          <factor>
                            <unsignedInt>
                            <unsignedInt> 1 <\unsignedInt>
                            <\unsignedInt>
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
              <constant>
              <keyword> if <\keyword>
              <seperator> ( <\seperator>
                <condition>
                  <expression>
                    <term>
                      <factor>
                      <identifier> Mod <\identifier>
                      <seperator> ( <\seperator>
                        <argumentList>
                          <expression>
                            <term>
                              <factor>
                              <identifier> s <\identifier>
                              <\factor>
                            <\term>
                          <\expression>
                        <seperator> , <\seperator>
                          <expression>
                            <term>
                              <factor>
                                <unsignedInt>
                                <unsignedInt> 4 <\unsignedInt>
                                <\unsignedInt>
                              <\factor>
                            <\term>
                          <\expression>
                        <\argumentList>
                      <seperator> ) <\seperator>
                      <\factor>
                    <\term>
                  <\expression>
                <seperator> != <\seperator>
                  <expression>
                    <term>
                      <factor>
                        <unsignedInt>
                        <unsignedInt> 0 <\unsignedInt>
                        <\unsignedInt>
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
                        <expression>
                          <term>
                            <factor>
                              <unsignedInt>
                              <unsignedInt> 0 <\unsignedInt>
                              <\unsignedInt>
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
                <seperator> } <\seperator>
                <\statement>
              <\constant>
            <\statement>
            <statement>
            <identifier> s <\identifier>
              <assignStat>
              <seperator> = <\seperator>
                <expression>
                  <term>
                    <factor>
                    <identifier> s <\identifier>
                    <\factor>
                  <seperator> / <\seperator>
                    <factor>
                      <unsignedInt>
                      <unsignedInt> 4 <\unsignedInt>
                      <\unsignedInt>
                    <\factor>
                  <\term>
                <\expression>
              <\assignStat>
            <seperator> ; <\seperator>
            <\statement>
            <statement>
            <identifier> dyn <\identifier>
            <seperator> [ <\seperator>
              <expression>
              <seperator> + <\seperator>
                <term>
                  <factor>
                    <unsignedInt>
                    <unsignedInt> 0 <\unsignedInt>
                    <\unsignedInt>
                  <\factor>
                <\term>
              <seperator> - <\seperator>
                <term>
                  <factor>
                    <unsignedInt>
                    <unsignedInt> 1 <\unsignedInt>
                    <\unsignedInt>
                  <\factor>
                <\term>
              <seperator> + <\seperator>
                <term>
                  <factor>
                    <unsignedInt>
                    <unsignedInt> 2 <\unsignedInt>
                    <\unsignedInt>
                  <\factor>
                <\term>
              <\expression>
            <seperator> ] <\seperator>
              <assignStat>
              <seperator> = <\seperator>
                <expression>
                  <term>
                    <factor>
                      <unsignedInt>
                      <unsignedInt> 1 <\unsignedInt>
                      <\unsignedInt>
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
                      <unsignedInt>
                      <unsignedInt> 1 <\unsignedInt>
                      <\unsignedInt>
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
                    <identifier> j <\identifier>
                      <assignStat>
                      <seperator> = <\seperator>
                        <expression>
                          <term>
                            <factor>
                            <identifier> s <\identifier>
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
                              <constant>
                              <keyword> if <\keyword>
                              <seperator> ( <\seperator>
                                <condition>
                                  <expression>
                                    <term>
                                      <factor>
                                      <identifier> j <\identifier>
                                      <\factor>
                                    <\term>
                                  <seperator> - <\seperator>
                                    <term>
                                      <factor>
                                      <identifier> i <\identifier>
                                      <\factor>
                                    <\term>
                                  <\expression>
                                <seperator> > <\seperator>
                                  <expression>
                                    <term>
                                      <factor>
                                        <unsignedInt>
                                        <unsignedInt> 0 <\unsignedInt>
                                        <\unsignedInt>
                                      <\factor>
                                    <\term>
                                  <\expression>
                                <\condition>
                              <seperator> ) <\seperator>
                                <statement>
                                <seperator> { <\seperator>
                                  <statements>
                                    <statement>
                                    <identifier> dyn <\identifier>
                                    <seperator> [ <\seperator>
                                      <expression>
                                        <term>
                                          <factor>
                                          <identifier> j <\identifier>
                                          <\factor>
                                        <\term>
                                      <\expression>
                                    <seperator> ] <\seperator>
                                      <assignStat>
                                      <seperator> = <\seperator>
                                        <expression>
                                          <term>
                                            <factor>
                                            <identifier> dyn <\identifier>
                                            <seperator> [ <\seperator>
                                              <expression>
                                                <term>
                                                  <factor>
                                                  <identifier> j <\identifier>
                                                  <\factor>
                                                <\term>
                                              <\expression>
                                            <seperator> ] <\seperator>
                                            <\factor>
                                          <\term>
                                        <seperator> + <\seperator>
                                          <term>
                                            <factor>
                                            <identifier> dyn <\identifier>
                                            <seperator> [ <\seperator>
                                              <expression>
                                                <term>
                                                  <factor>
                                                  <identifier> j <\identifier>
                                                  <\factor>
                                                <\term>
                                              <seperator> - <\seperator>
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
                                      <\assignStat>
                                    <seperator> ; <\seperator>
                                    <\statement>
                                  <\statements>
                                <seperator> } <\seperator>
                                <\statement>
                              <\constant>
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
                                <seperator> - <\seperator>
                                  <term>
                                    <factor>
                                      <unsignedInt>
                                      <unsignedInt> 1 <\unsignedInt>
                                      <\unsignedInt>
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
                              <identifier> j <\identifier>
                              <\factor>
                            <\term>
                          <\expression>
                        <seperator> >= <\seperator>
                          <expression>
                            <term>
                              <factor>
                              <identifier> i <\identifier>
                              <\factor>
                            <\term>
                          <\expression>
                        <\condition>
                      <seperator> ) <\seperator>
                      <\loopStat>
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
                              <unsignedInt>
                              <unsignedInt> 1 <\unsignedInt>
                              <\unsignedInt>
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
                <seperator> <= <\seperator>
                  <expression>
                    <term>
                      <factor>
                      <identifier> n <\identifier>
                      <\factor>
                    <\term>
                  <\expression>
                <\condition>
              <seperator> ) <\seperator>
              <\loopStat>
            <\statement>
            <statement>
              <writeStat>
              <keyword> printf <\keyword>
              <seperator> ( <\seperator>
                <expression>
                  <term>
                    <factor>
                    <identifier> dyn <\identifier>
                    <seperator> [ <\seperator>
                      <expression>
                        <term>
                          <factor>
                          <identifier> s <\identifier>
                          <\factor>
                        <\term>
                      <\expression>
                    <seperator> ] <\seperator>
                    <\factor>
                  <seperator> / <\seperator>
                    <factor>
                      <unsignedInt>
                      <unsignedInt> 2 <\unsignedInt>
                      <\unsignedInt>
                    <\factor>
                  <\term>
                <\expression>
              <seperator> ) <\seperator>
              <\writeStat>
            <seperator> ; <\seperator>
            <\statement>
          <\statements>
        <\compoundStatement>
      <seperator> } <\seperator>
      <\funcDecl>
    <\program>
  <end> ÿ <\end>
