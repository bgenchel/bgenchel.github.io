let DATA = {
    "content": {
        "text": "",
        "items": [
            {
                "title": "Jazz Melody Generation with Deep Reinforcement Learning",
                "year": {"begin": 2018, "end": "present"},
                "description": [
                    `Deep Learning approaches to music generation have become increasingly popular, but current systems
                    lack the ability to learn and produce coherent long-term structure in music &mdash; these systems do
                    not understand what they are learning, and as such are not able to use their knowledge to
                    communicate musically, or act musically creative in the way a human would. One of 
                    the most fascinating things to me about conducting machine learning and generative systems research, 
                    and specifically conducting this research with respect to music, is that I get to grapple with these types
                    of problems which bridge engineering with an understanding of our own learning processes. What does 
                    it mean to communicate musically? What does it mean to be creative in a musical fashion? How does 
                    musical learning happen? What types of processing and memory are involved in music learning, and how can we model it?`,
                    `Learning heirarchical long term structure appears key to moving these systems, and thus our
                    understanding of these questions, forward. For my Masters Project at GTCMT, I chose to apply 
                    Deep Reinforcement Learning (DRL) to music generation due to its recent success in learning long term
                    structure for complex strategy games such as Go, Shogi, League of Legends and StarCraft. Like these games, music is a
                    task which provides sparse rewards (you don't know whether a musical phrase is good just from
                    hearing a single note &mdash; you have to hear the whole thing), and a task which contains multiple
                    heirarchical levels of structure.`,
                    `Alpha Zero, Google DeepMind's extraordinary DRL system that mastered multiple games, has also
                    been described as playing in a creative fashion.`,
                    `</p><blockquote><p>
                        “Impressively, it manages to impose its style of play across a very wide range of positions and 
                        openings,” says Matthew [Sadler], who also observes that it plays in a very deliberate style from its 
                        first move with a “very human sense of consistent purpose”.

                        “Traditional engines are exceptionally strong and make few obvious mistakes, but can drift when faced with positions
                        with no concrete and calculable solution,” he says. “It's precisely in such positions where ‘feeling’, ‘insight’ or
                        ‘intuition’ is required that AlphaZero comes into its own."<br><br>
                        &mdash; 
                        <a href="https://deepmind.com/blog/alphazero-shedding-new-light-grand-games-chess-shogi-and-go/">
                            DeepMind, AlphaZero: Shedding New Light ...</a>
                    </p></blockquote><p>`,
                    `DRL has been scarcely applied to music due to its abstract and subjective nature; how can you provide
                    reward a system for making good music when what makes music good is so unclear? However, I still believe
                    there is a lot of promise in this approach, especially with the development of techniques such as adversarial
                    learning, curiosity and inverse reinforcement learning, each of which allows models to learn reward
                    functions in different ways.`,
                    `This project does not cover all I am interested in exploring with respect to DRL, but represents a first step into
                    the field for me. It aims to combines two previous sequence generation approaches which use DRL, 
                    <a href="https://www.aaai.org/ocs/index.php/AAAI/AAAI17/paper/viewPaper/14344">SeqGAN</a> and <a
                       href="https://openreview.net/forum?id=Syyv2e-Kx">TunerRL</a>. My current progress is detailed in the
                   document posted here.`
                ],
                "media": {
                    "type": "document",
                    "items": ["res/images/projects/DRL_4MG.jpg"],
                    "download": null,
                    "caption": null
                }
            },
            {
                "title": "Explicitly Conditioned Melody Generation: A Case Study with Interdependent RNNs",
                "year": {"begin": 2018, "end": 2019},
                "description": [
                    `This project examines the effects of explicitly conditioning a deep learning music generation system 
                    with various musical factors. Explicit conditioning here refers to deriving specific,
                    human-parsable information from the data (e.g. chords, note durations, note pitches, note positions
                    relative to a bar) from the data, processing them separately, and then feeding them to the model
                    along side the primary information to be modelled. The model in question consists of two parallel
                    LSTM-RNNs (Long Short Term Memory - Recurrent Neural Network), one that models and generates note
                    pitch sequences, and the other that models and generates note duration sequences. The outputs of
                    each are combined 1 to 1 to form a monophonic melody.`,
                    `This project initially began with the model architecture, which I conceived while trying to think
                    of an appropriate baseline for another idea for my graduate research project for the 2018. As a jazz
                    musician, I tend to think of music as a set of separate but co-dependent parts, such as harmony,
                    melody, rhythm, that are embodied with finer detail in an arrangement or performance. Lead sheets
                    provide these core components, with section markers, overall feels (e.g. swing, bop), chord labels, 
                    key changes, etc. and musicians and bands interpret them in their own way. 
                    As such, I wanted to pursue a project that would reflect and explore that line of thinking. I continued
                    development on this project while working as a visiting researcher in the 
                    <a href="https://musicai.citi.sinica.edu.tw/">Music and A.I. Lab</a> in Taipei, Taiwan over the
                    following summer, and began collaborating with my colleague 
                    <a href="https://ashispati.github.io/">Ashis Pati</a> to evaluate it and publish the
                    results.`,
                    `I published the model architecture of this work as a late breaking abstract at the 
                    <a href="https://csmc2018.wordpress.com/programme/">Computer Simulation of Musical Creativity
                    Conference in 2018</a>, and plan to submit a paper on the results of using the model to compare
                     the effects of explicit conditioning factors to the 2019 
                    <a href="http://musicalmetacreation.org/">Musical Metacreation Workshop</a>.`
                ],
                "media": {
                    "type": "image",
                    "items": ['res/images/projects/min_model.jpg'],
                    "download": null,
                    "caption": `Model architecture overview — This figure displays the all different musical data series used in the
                    model, and how they are processed and used for conditioning. In particular, this figure shows
                    all factors being applied simulataneously; one configuration of many that we tested. Other 
                    configurations can be derived from this one by selectively removing a subset of connections 
                    prior to the embedding concatenation operation.`
                }
            },
            {
                "title": "Ghost in the 3D Printer - A Musical Painting Robot",
                "year": {"begin": 2018, "end": "present"},
                "description": [`Description coming soon!`],
                "media": null
            },
            {
                "title": "What Makes Machine Music Machine Like?",
                "year": {"begin": 2018, "end": null},
                "description": [
                    `</p><blockquote><p>
                        &nbsp;&nbsp;&nbsp;&nbsp;Can humans truly tell the difference between music composed by humans and music generated by a 
                        modern deep learning based statistical model? Without the bias of knowing whether the music they 
                        hear is composed by a machine or a human, what characteristics would people identify as human like,
                        or machine like?
                        <br><br>
                        Generally speaking, it appears intuitive that it would be easy for most people to differentiate a 
                        piece of music produced by a human from one produced by a modern deep learning model. One need only listen 
                        to a substantially long generation from any of these systems to intuit that the layman who inevitably 
                        asks if researchers are attempting to replace human musicians has nothing to fear at present,
                        [...]. In the event that making such a classification is in fact as easy as it appears, 
                        we would not know for certain, as the majority of evaluations presented in this area compare their 
                        model’s output to a set of baseline models along a set of objective (though contestable) metrics or 
                        via a listening test in which each contestant is rated along preset dimensions. 
                        Thus, there has been little work in the way of comparing machine generated music to actual music; 
                        characterizing the perceptual differences between the two and discovering how people listen and 
                        what they listen for in the context of these studies.
                    </p></blockquote><p>`,
                    `In this pilot study, my final project for the Music Perception and Cognition class at Georgia Tech,
                    my teammates and I surveyed a small population of students in the course (~14) to gain qualitative
                    insight into the perceived differences between real melodies and machine generated melodies. We
                    presented each subject with pairs of melodies, one real and one generated, played over the same set
                    of chords and asked them to provide both quantitative ratings and qualitative responses.`,
                    `The results of this study are presented in the paper provided here. I hope to pursue a full, formal version 
                    of this study in the near future.`
                ],
                "media": {
                    "type": "document",
                    "items": ["res/images/projects/mpc_report.jpg"],
                    "download": "res/docs/projects/mpc_report.pdf",
                    "caption": null
                }
            },
            {
                "title": "PyPadberg",
                "year": {"begin": 2018, "end": null},
                "description": [
                    `In 1964, Harriet Padberg completed the first dissertation on algorithmic composition using a
                    computer, <i>Computer Composed Canon and Free Fugue</i>, which converted text inputs into melodies using
                    a custom algorithm. This work stood out at the time for using a text-to-music mapping instead
                    of the random number generation based systems used in her contemporaries’
                    pieces, e.g. Illiac Suite by Lejaren Hiller. It received moderate attention in the years
                    following its creation, including a 1968 sonic realization by Max Matthews and mention by Hiller in a 1970
                    survey of computer-generated music. In the present, her work has largely been forgotten; it is not 
                    commonly known, nor spoken about outside of select papers, presenting not only a lack of attention 
                    towards a significant historical work, but also the loss of opportunity to learn from and adapt it 
                    for new musical creations.`,
                    `In this project, my teammates <a href="http://richardsavery.com/">Richard Savery</a>, Jason Smith, and I 
                    dug up all the information we could on Padberg to develop our own 
                    <a href="https://github.com/bgenchel/pypadberg">recreation in python</a>.
                    We then reached out to three composers to create compositions using the system in whatever way they saw fit.
                    The results were three widely varied and unique statements on feminism, alternative tuning systems
                    and the use of text in music.`,
                    `This work has been accepted to the "Women, Music, Technologies" session by the Committee on the
                     Status of Woman of the Society for Music Theory at the 2019 Society for Music Theory meeting.`
                ],
                "media": {
                    "type": "carousel",
                    "items": ["res/images/projects/pypadberg/splash.png",
                              "res/images/projects/pypadberg/text_entry.png",
                              "res/images/projects/pypadberg/processing.png",
                              "res/images/projects/pypadberg/rendering.png"],
                    "download": null,
                    "caption": `
                        PyPadberg Interface &mdash; this slideshow displays the interface of the PyPadberg program in order of
                        appearance: Title Screen, Text Entry, Text Processing, Rendering. The title screen shows a woman working
                        on the IBM 1620 computer, the same computer Harriet Padberg used for her dissertation.`
                }
            },
            {
                "title": "Sound Happening",
                "year": {"begin": 2018, "end": null},
                "description": [
                    `Sound Happening is an ongoing interactive musical installation project housed by the 
                    <a href="https://expressivemachinery.gatech.edu/">Expressive Machinery Lab</a> at Georgia Tech. Its
                    purpose is to allow participants to engage in an active, collaborative, and most importantly playful
                    musical experience. Designed to be easy to take and install anywhere, it consists of only a webcam, a
                    laptop to run color tracking software and send messages to Ableton Live, and colorful bouncy balls.`,
                    `During the Spring of 2018, I worked on Sound Happening alongside my colleague 
                    <a href="http://richardsavery.com/">Richard Savery</a>. We implemented new functionality, better,
                    cleaned the code base, and developed new sounds and loops. For my own sound design, I focused on using
                    randomness such that the sounds produced by the motion of each ball would be different each time.`,
                    `A video explaining the concept of Sound Happening (made prior to our work), as well as a video showing 
                    our progress are presented here.`
                ],
                "media": {
                    "type": "youtube",
                    "items": ["https://www.youtube-nocookie.com/embed/8sUmnQvu7bQ", "https://www.youtube-nocookie.com/embed/VqLmMAHYCBc"],
                    "download": null,
                    "caption": null
                }
            },
            {
                "title": "Evolving Towards Green Sleeves",
                "year": {"begin": 2018, "end": null},
                "description": [
                        `Evolving Towards Green Sleeves is a computer music composition which sonifies the process of a
                        machine learning system learning how to play a song. Specifically, I implemented an evolutionary
                        algorithm from scratch in python, and had it overfit on the melody to green sleeves, represented as 
                        parallel midi note number and duration token sequences. I trained the system for 700 iterations,
                        with 350 candidates generated and 40 candidates selected per generation. Starting with a totally
                        random set of candidates, each iteration the system computes the mean squared error between each
                        candidate and the ground truth, keeps the top 40 candidates with the lowest losses and throws away the
                        rest, generating a new set of 350 candidates via random sampling from the selected set. A random
                        gaussian mutation is added to the new candidates.`,
                        `I tracked the average loss during training and selected random candidates from the pool every time
                        the loss would decrease by a relatively significant amount. The core of the final piece is the result of
                        concatenating these in order. I wanted to emphasize a notion of moving from chaos to order, and so
                        near the beginning, had several samples playing over each other with heavy reverb / distortion while near the end,
                        I selected only one or two melodies to play with clarity.`,
                        `Code for the project can be found 
                        <a href="https://github.com/bgenchel/Evolving-Towards-Green-Sleeves">here</a>`
                ],
                "media": {
                    "type": "spotify",
                    "items": ["https://open.spotify.com/embed/track/4Y8r1jX0Ei9G3Ky7cYt7ep"],
                    "download": null,
                    "caption": null
                }
            },
            {
                "title": "BreadFighter: Breadboard MIDI Controller",
                "year": {"begin": 2018, "end": null},
                "description": [
                    `This device is a custom built MIDI controller using a wide range of sensors and inputs over four
                    breadboards, motivated by an assignment for a class at Georgia Tech which asked students to create a
                    custom MIDI inputs to MaxMSP. While the assignment asked for much less, I was really motivated
                    to build a full controller, inspired by all the different varieties of MIDI controllers I had been
                    seeing both inside and outside the Music Technology program.`,
                    `The controller, built on an Arduino Uno, sends messages over serial which are read by Max/MSP, then
                    forwarded to Ableton Live over OSC. The class was so impressed with my design that I was invited to 
                    perform with it at the 2018 Guthman Musical Instrument Competition pre-show. While I myself am not 
                    experienced performing with MIDI controllers, the breadboard controller served as a point of interest 
                    for attendees, who frequently visited my booth to play with it and ask questions.`,
                    `The first video shown here is a walk through of the controller. The second, a short clip from the 
                    Guthman pre-show (I used a launchpad to record, store and launch loops created with the controller).`
                ],
                "media": {
                    "type": "youtube",
                    "items": [
                        "https://www.youtube-nocookie.com/embed/TAraRy9DHk4", 
                        "https://www.youtube-nocookie.com/embed/qJmrfS5dx8o"
                    ],
                    "download": null,
                    "caption": null
                }
            },
            {
                "title": "NSF Grant Proposal: A Novel Deep Learning Model for Musical Creativity",
                "year": {"begin": 2017, "end": null},
                "description": [
                    `This grant proposal was written by me and my colleagues <a href="https://richardyang40148.github.io/">Li-Chia
                    "Richard" Yang</a>, <a href="https://ashispati.github.io//contact/">Ashis Pati</a> during my first
                    semester at Georgia Tech on behalf of professors <a href="https://www.linkedin.com/in/weinberggil/">Gil
                    Weinberg</a> and <a href="https://www.alexanderlerch.com/">Alexander Lerch</a>. It describes a novel
                    deep learning system which would be trained using information from both scores and semantically
                    meaningful perceptual and performance features extrated from audio recordings of performances of said scores. 
                    It would also use detailed, semantically meaningful score annotations provided by experts. Positioned squarly 
                    as research towards computational creativity, rather than higher quality generation for other reasons, 
                    this proposal targeted Jazz improvisation generation as a genre of music for which creativity was more
                    necessary and from which creativity could be more easily detected and evaluated.`,
                    `Though this proposal was rejected, it was a valuable experience for me to have especially at the
                    beginning of my Master's program. I learned a lot about proposal writing, and deep learning for
                    creativity and music generation through the process.`
                ],
                "media": {
                    "type": "document",
                    "items": ["res/images/projects/2017proposal.jpg"],
                    "download": "res/docs/projects/2017proposal.pdf",
                    "caption": null
                }
            },
            {
                "title": ".dotfiles",
                "year": {"begin": 2016, "end": "present"},
                "description": [
                    `I am a huge fan of the terminal. My workflow for any software project, and even some writing
                    assignments, uses TMUX, Vim, and a ton of plugins. I also use zsh as my shell, with Oh-My-Zsh as my
                    plugin manager.`,
                    `I've collected all my dotfiles in a repository, and provided some installation scripts to help both me
                    (when I gain access to a new server, or refresh my computer) and friends interested in adopting the
                    terminal workflow get everything needed in place quickly.`,
                    `Special thanks to <a href="https://www.linkedin.com/in/alexyang2818/">Alex Yang</a>, who helped me get
                    started with all this stuff.`,
                    `<a href="https://github.com/bgenchel/.dotfiles.git">Check out my .dotfiles!</a>`
                ],
                "media": {
                    "type": "image",
                    "items": ["res/images/projects/dotfiles.png"],
                    "download": null,
                    "caption": `Screenshot of my terminal - I use iterm2, tmux, vim, and zsh with the myagnoster theme. You
                        can see here that I use command highlighting and auto complete plugins for zsh, and the
                        YouCompleteMe plugin for vim. I'm also a permanent user of the monokai colorscheme.`
                }
            },
            {
                "title": "Web Development",
                "year": {"begin": 2013, "end": "present"},
                "description": [
                    `In 2013, I volunteered to take on the position of Webmaster for my professional engineering
                    fraternity, Theta Tau. Though an Electrical Engineering major, I knew I had a knack for coding from
                    my introductory C class and MatLab, and wanted a reason to learn more. I got the job (no one else
                    wanted it), and remained in the position for two years, struggling tooth and nail against an
                    avalanche of my own ignorance and no one to guide me. Several years later, with many attempts of
                    varying degrees of success later, I am somewhat competent.`,
                    `I've built many pages, both from scratch and from templates, using jquery, bootstrap, vanilla 
                    javascript, and a variety of plugins. I've also worked on backend development, with Google App Engine, 
                    AWS, PostgreSQL, MySQL, NodeJS and Express.`,
                    `Though Wix and SquareSpace make great looking sites in a short amount of time, I always challenge
                    myself to make my own. This page was built from scratch using JQuery and Bootstrap, and I have 
                    plans to make it a kind of instrument using Tone.JS in the near future.`
                ],
                "media": null 
            }
        ]
    }
}
