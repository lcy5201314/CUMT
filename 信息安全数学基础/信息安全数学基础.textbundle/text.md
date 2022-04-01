# 信息安全数学基础

## 整数

### 整除

- 定义

	- ![](assets/d327fdf06568a895f3ea6d0f87752a44c64ddb9cae90f69f56e89944210fe87b.png)

- 性质

	- 特性

		- (1）当b遍历整数a的所有因数时，－b 也遍历整数a的所有因数
		- （2）当b遍历整数 a的所有因数时，a/b 也遍历整数a的所有因数
		- (3) 0是任何非零整数的倍数．
		- (4) 1是任何整数的因数
		- (5) 任何非零整数α 是其自身的倍数,也是其自身的因数

	- 传递性

		- ![](assets/c83aad3715b72885ddef80f87be340fd9c7eca91288435f9b3fac80f0f9138f3.png)

	- 加减保持性

		- ![](assets/b97963213e9631d0900d4ff5ba726af7412507d7207694abf1ee9bb6cbcfc9d7.png)

	- 线性组合性

		- ![](assets/3dcebf0447da1d300d90c812798d953312a9db154d439641a32ad7772403b127.png)
		- ![](assets/71fa9759c1e20a7c56e219cf31a30f7586e0880dd214b74fc67b330dfe52bab9.png)

	- 互逆

		- ![](assets/60aa10b125e742c07c932dbff3b1c05a416beabbb1d452c354fb1efb39961f5d.png)

### 素数

- 定义

	- ![](assets/39d1c2a5404c3f4c4fb924232d25dc4ebd672af61c374c816e6e030f69a8f767.png)

- 筛选法

	- Eratoshenes筛法引理

		- ![](assets/e44f7f8a0a0db58838c7783804db768c841b35b8c41495cfc9be3d89a67e1f9f.png)

	- Eratoshenes筛法

		- ![](assets/9c0bfe020e319e3d3c0eb256322aa880520a14e2b7372624a141fa57db2fdc5a.png)

- 性质

	- 无穷性

		- 素数有无穷多个

### 欧几里得除法

- 定义

	- ![](assets/17cda42d44de030f24ffc7ab61b3479e6bb05bf2388b243374b083ae04de3b56.png)
	- ![](assets/bc2dfbb55665ecc8154f44054264c6568637311e638019bbefcc536a4656347b.png)
	- 补充

		- ![](assets/9f9e7c47249048e60bbeed09cc300a25922efcf1ea37579cd6a180b625bed771.png)

- 素数平凡判别法

	- ![](assets/46624170ece122f3dbb13d7971711ae661b01369c61edacb9dbc55f03343b369.png)

- 一般余数定义

	- ![](assets/4f765d2d915e396ef388328066ffe732610265a28715e2572fe03c6c82bd0622.png)
	- 延拓余数形式

		- ![](assets/8a51799c39c418665d288f0079e34ba1ae0b4da426973081e3d0776a20b5bc18.png)
		- 例题

			- ![](assets/7076ff3ac44250151bded9f2b5597ccf01b48ed3dcd5c8d0086de0dddefc1743.png)

### 整数的表示（多项式）

- b进制表示（多项式形式）

	- 定义

		- ![](assets/1dfa299563fab52a80225cfc5f1af30b34f981df8b3e7aa4d3fc0182c04737d6.png)
		- 详细

			- ![](assets/539c9b5bae47e73f74afe9b54c28c11c7e70aa45c983addceae7dbd99a9f0ab6.png)

	- 转换

		- 这里不多介绍，除取余法

	- 运算（多项式类似）

		- 加法
		- 减法
		- 乘法
		- 除法（欧式空间下除法）

- 复杂度（极限下无穷量）

	- 大O符号

		- ![](assets/8c07dbf201afee1a714f3cfddd5ee6c54d055be54bea5ec1b03138ed0a7ef194.png)

	- 小o符号

		- ![](assets/805bda0cd4b4dbe308e1c197058113b2ff341e877b6eae9a62c8846b3775b925.png)

	- 运算

		- 加法

			- ![](assets/b1acb20d80901181ea68a6d7136c02648049a12d14270b39dadb93fc204606a8.png)

		- 减法

			- ![](assets/302d4fbece046885fcecff701c8b7f8ad5f016043066409a9660b8b2ae9421e0.png)

		- 乘法

			- ![](assets/058ae17d274d56277682ef1498ad089a1cf468abefe5725deb956005b492b0e9.png)

		- 除法

			- ![](assets/b4f6aedbb7840c3fab3f49a193493b5d93c3163f20584731dc4f163c6f68f7f6.png)

### 最大公因数

- 定义

	- ![](assets/ae6d3525f5a0efed0de8c98ee7e2e450d540a7e8fa9df4eb97d41fa3761da2e3.png)
	- 补充

		- ![](assets/36df8578e8cc3445e37217b7be9923dc216373f1d02cddc035f62e8a0f73144e.png)
		- ![](assets/0a742f8ed4b271d34933728126c1eba171ce37f696a0debba392d76f71567cee.png)
		- ![](assets/578a75395511860825f8d61700831c99f4f7d1808e9d081082cbef823a9665d4.png)

- 性质

	- 相等

		- ![](assets/6d0bea78f0702fea591dcdd87d6b78a8a6fc1e7105493c7f22fcb60d322226c8.png)

	- 0性

		- ![](assets/1e5483a877880435c06ac21be61876400057fa2df0da6d165b6269654acfcc66.png)

	- 欧几里得除法引理

		- ![](assets/909a4569828a4cd2254febfc6d8f0f718b5e48cd3a778b385360852f43631b78.png)

### 广义欧几里得除法

- 定义（辗转相除法）

	- ![](assets/914bf315b949488cd58ab6480001a9fb051a1485c0b1bb935bdba5c853a99e36.png)
	- 例如

		- ![](assets/d5d3ce1918f999b7aa96dab8db6ad160eff7abb49df6b7780d00690c68bd9ab6.png)

- 性质

	- ![](assets/ad0ebd0d8aee0b4e0924b585d8d1a0a1007f94ea34d58acfe526f33f4dc63412.png)
	- ![](assets/93416f7e95168c4e21f0bac85a699996b4bc3a1dd8d424f8b6e8857dcbfa1f0e.png)

- 贝祖等式

	- ![](assets/a7ed0951dce180afdc5634d669d99a1bfe0a4b131067ff319489431531544202.png)
	- 例如

		- ![](assets/3d9718ba28f49f49fba718e440be72889deac71276973213dae9be18e83ceb3d.png)
		- ![](assets/6488feb75469d91eb28b01ba85cdb9cff8e617ce1ceb6830fbbdbe5840e6b33e.png)

- 证明

	- ![](assets/0539fdbcb90ff63498319773386032ac9b17ee5a4995c56365d156d9b0a221da.png)

		- ![](assets/9eaa4ca90a4df70f452a532e05dc74294d8ff28f84cc1b85f45c6822a97a38cb.png)

	- ![](assets/ef81bd82986eca9d5ca54c1779850bd43fefbfbab4c0bc64fd499ec49cca18c6.png)

		- ![](assets/6758ed91dbd6203178e2165273efcd54235be6becfe42f2a7d8661342124bb80.png)

	- ![](assets/d91bee7611335830e648ed637d49b64bd5bcabe8a5487fcdd2d9cfd798a19ce8.png)

		- ![](assets/640fe111291a32c673183ab73d43cd7f4364a9d3ec5f688c3b7c898ed79b1802.png)

- 应用

	- ![](assets/4e618af5f76f6bfd4aa6a3f8dcbee3d7c34d638640992570cf2d69e58c76b03b.png)

### 最大公因数

- 互素定义

	- ![](assets/ac32022047ebb7c0884b6b3cb584e47d3460897026a6d443629d14a4ef5c2f81.png)

- 最大公因数定义

	- ![](assets/70a6bb711c29c75cc2548eeebef30110f131cb67fdd52105f13ef9dad54b817f.png)

- 推论

	- ![](assets/3ff157544e13583814f9278bd590479d2ff9be864acae06ce9154cc38e5873c9.png)
	- ![](assets/2b104e32bd9e44af157676fa542fb295b0bf32a837f8fdab9945923ea41ccedf.png)
	- ![](assets/6a147446eebfc9c42ef48549e161478b9f93463a2bcf1ab240887ed7f8f93c4a.png)
	- ![](assets/3c76cad1f46461dcf786777557737ce47ff24d9d94066b29a4093782cd5ee9ff.png)

		- 可以写成行列式形式

	- ![](assets/6c90510b5365daaaa6d47f5e7e26026b6b1f7bb5d3a40204e8b29b4c744e933e.png)

- 计算定理

	- 线性递推

		- ![](assets/f46f1fa3012c4b74fcf4383863e7e27dad1c806be96d2f5e196b82569054f937.png)

	- 指数

		- ![](assets/23b01a653e20dfe5de85ec93a29af7a98002848d8c68627276e7d858dbb75837.png)
		- ![](assets/eeea62642abf92062b8493146c3743d629789915f91a01e3aff1f47a51168a8f.png)
		- ![](assets/4c8d9645154af9b5ea958ffb6ab07d6296c09de4e2a4725515c3012ea35d4e87.png)

### 最小公倍数

- 前提引理推论（整数性质扩展）

	- ![](assets/fbc57ed8b3b8b9339304e3715bfa3358919dd717e206e79f01afdd23ed4d19b7.png)
	- ![](assets/1d8f9ec4ce88538c403fd098a4c398c7830b2d26d6706eda350a6cb39a839a1c.png)
	- ![](assets/473398b9e64386e96d7528fbe0e573c9fdc6596b2086f4d4d345763b787b65ce.png)

- 定义

	- ![](assets/034a0641a285d4914638924b918c879270477773dc67bcfa14cc6be3a7fdc4d5.png)
	- ![](assets/ebb37d98db32cc4ae46793f874c19b63e74196cad097b65d927a5d7a938b8ab1.png)
	- ![](assets/dc5b8624a0cb4d9db21f11058e8754c5e8aef63545120d1a84018792c28ebff3.png)

- 最小公倍数与最大公因数的关系

	- ![](assets/54200eaeaa276a106815bd47d18281244bff37557ed71f4452ffed16104fe212.png)

- 拓展多个

	- ![](assets/d78772268e6193c6f5f6a0e9cc3038cf4b5fe865f82fe4fcdab8c081fa3a1f45.png)
	- ![](assets/6cc4659322e87939a3e77f1c2f9cf4bc2d417a1ace9fad776eb00133a05a0004.png)

### 整数分解

- 整数分解定理

	- ![](assets/cdd15d67efc334001cbe2a3d1b477074bf7f53b8373277bd6e0750ee4281bb9e.png)

- 例题

	- ![](assets/db02097482c4962748b7d1f8e0233fcb87d73f0aa27fe27cd92eb939e15ae55e.png)

### 素数算术基本定理(多项式形式重根)

- 算术基本定理

	- ![](assets/15ef5549220bd5bd535866e057b0579665d9de8789083e1a2409b418d088babe.png)
	- 这里素数乘积，表示素数开始作为空间的基，了解素数就可以掌握这个空间映射

- 标准分解式（加入重根）

	- ![](assets/302a7d76b21c9acb51ed8131b41e3a85ade626c099c294f8f90f9367a352284c.png)

- 因式分解

	- ![](assets/0c0f7ff10520e6eb8eebb8e75b7c314ccd01318fc2718e36ec347d00d7544142.png)
	- 素数组合

- 最大公因数额最小公倍数的内涵

	- ![](assets/988b25884b9514246d9a3229da7738c55d7db4521eea4882d0d043cc07613d80.png)
	- 推论

		- ![](assets/1375fb0983112bf13910127dee8eeb6811d7d856c890815cf3533d045e31886e.png)

	- 推论n个

		- ![](assets/170b5387f6e407c7e1218737eebf28b9d1218136ac1e5af39c0f4dbd3ae926d5.png)

- 特殊结论

	- ![](assets/97da9c572814de6ae373a257fd1b73b4a58532487f361499da79b2769b6da989.png)

- 素数定理

	- ![](assets/c53a53c97eefce64092939b9db4f69a434ef7d0ce8ee3a11c0b95136e41e81dc.png)

- 切比谢夫不等式

	- ![](assets/297b9f5efa217a6c04779a75fde47f855a84552e6273f2881e8bd836b5a42671.png)

## 同余

### 同余

- 概念

	- ![](assets/36d22195696490c5f2d14d27af252b6ee8336218696b4d4dfdaf8a62ed8d2570.png)

- 判断原理

	- ![](assets/13edf7c44b216e6412d957a7041c69fbf93bc4eaac27d1750136e942441000fa.png)

- 等价关系的性质

	- 自反

		- ![](assets/83a3803345ed96b0bd09e7dcb6a3a30ea2490508977577e332da672497cca4f5.png)

	- 对称

		- ![](assets/6225c63793dc2827a45966c2328242bb0c1b6afb5c836e61916bb7ea2630fee5.png)

	- 传递

		- ![](assets/da4828dc967cb946c52e8d80f0ab95af91df4fa73102b67b94172ab8d479709b.png)

- 推论

	- 余数相同判定

		- ![](assets/4586abce717aa895d2a71d212123963ee55c21b7287305c84fd4a75884d14621.png)

- 特性

	- 相加相乘（满足线性空间）

		- ![](assets/7ce32ff8e28a066079bb235ad23960f2e9ceb1114cbb8151240b5520614ca7e4.png)

	- 空间相等

		- ![](assets/fb5583191734b316fcfc35f3a6f115707446c93f6ed5105459cb8a16917b60b8.png)

	- 3，9特性

		- ![](assets/18daea7fd0a316def9ca8a3d60d7ccdd776d3ac17d456d80b8bb5c557ab1fac7.png)

	- 7,11,13特性

		- ![](assets/d3608138d4e7d6f356580660345d933ead096f6325437fd3700d3c05e054791c.png)

- 性质

	- ![](assets/1b674ea08e18eb9a63273bd627dfdbad7a636fbbbbb7c0268d44442f39eb3e99.png)
	- ![](assets/d4728d02095455e62ca6ef8990fff0dc99a9255d9f60be854d5766c12018689b.png)
	- ![](assets/48c703a01bbb676a5e237e75ea674a9fb8cc9fa5135f8ee2eb4f5d7d1478f081.png)
	- ![](assets/7a4c31ab05fc046bf8a040acf5960e4f54a3ba9ee97750256e9070ed3eabfc67.png)
	- ![](assets/04e792440274ede5b33789397640819570fb3eda25a73c9d5efc41e0c73acfe9.png)
	- ![](assets/4b605f3fb1c52c6d56502feafa4eb9f8138d32a540598296bb73ba3915ad5108.png)

### 剩余类

- 定义前提

	- ![](assets/44ffb76b2fc18885e433ba7f5c247435fbfc83477d8e5a78eee774014b15b1b8.png)
	- ![](assets/b3acb4456e2cecb380c73590ebd3d765d745f29255620a6441e51e49cbed469c.png)

- 完全剩余类

	- 定义

		- ![](assets/e3a81efdffb91585ab48d102140652780ee4a830f37ba414d684f85ea15b3dbf.png)

	- 性质

		- ![](assets/0f2728f38749ce9b5ca965d228779695279b348d593854626f7016e2e4ab8dcd.png)
		- ![](assets/90e6b78617b76716d25e5f3e661ca573572fd029138053687a124a3aba410425.png)

	- 判定定理

		- ![](assets/47a25055b0c4de36f6938af8f634fc20b2a3f2a24bdc2b1e7f1af1ff6e19b68c.png)

	- 类型

		- ![](assets/ed6bcb48875da067e8c6e80089bc4d8458e8b85c09a2c92af43d7ddff5daf5f9.png)

### 欧拉函数

### 经典定理

### 模重复

## 同余式

## 二次同余式与平方剩余

## 原根与指标

## 素性检验

## 连分数

