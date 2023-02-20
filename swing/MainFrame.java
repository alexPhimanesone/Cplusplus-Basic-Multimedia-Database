import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class MainFrame extends JFrame
{
    private static final long serialVersionUID = 1L;
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;

    /* Client */
    static Client client = null;
    
    /* Components */
    JTextArea textArea;
    JTextField rechercherMultimediaField, rechercherGroupeField, jouerField;

    /* Actions */
    Action sentence1Action, sentence2Action, closeAction;


    /*****************************************
     **************  Constructor  ************
     *****************************************/

    public MainFrame()
    {
        /* Instanciating the actions */
        
        sentence1Action = new AddSentence1Action();
        sentence2Action = new AddSentence2Action();
        closeAction = new CloseAction();
        
        /* The menu bar */

        JMenuItem itemSentence1 = new JMenuItem(sentence1Action);
        JMenuItem itemSentence2 = new JMenuItem(sentence2Action);
        JMenuItem itemClose = new JMenuItem(closeAction);
        
        JMenu menu = new JMenu("Actions Menu");
        menu.add(itemSentence1);
        menu.add(itemSentence2);
        menu.add(itemClose);

        JMenuBar menuBar = new JMenuBar();
        menuBar.add(menu);

        /* The tool bar */
        
        JButton btnAddSentence1 = new JButton(sentence1Action);
        JButton btnAddSentence2 = new JButton(sentence2Action);
        JButton btnClose = new JButton(closeAction);

        JToolBar toolBar = new JToolBar();
        toolBar.add(btnAddSentence1);
        toolBar.add(btnAddSentence2);
        toolBar.add(btnClose);
        
        /* The request panel */

        JLabel rechercherMultimediaLabel = new JLabel("Rechercher Multimedia:");
        JLabel rechercherGroupeLabel = new JLabel("Rechercher Groupe:");
        JLabel jouerLabel = new JLabel("Jouer:");
        
        rechercherMultimediaField = new JTextField();
        rechercherGroupeField = new JTextField();
        jouerField = new JTextField();

        JButton rechercherMultimediaBtn = new JButton("OK");
        JButton rechercherGroupeBtn = new JButton("OK");
        JButton jouerBtn = new JButton("OK");

        rechercherMultimediaBtn.addActionListener(new rechercherMultimediaListener());
        rechercherGroupeBtn.addActionListener(new rechercherGroupeListener());
        jouerBtn.addActionListener(new jouerListener());

        JPanel requestPanel = new JPanel();
        requestPanel.setLayout(new GridLayout(3, 2));
        requestPanel.add(rechercherMultimediaLabel);
        requestPanel.add(rechercherMultimediaField);
        requestPanel.add(rechercherMultimediaBtn);
        requestPanel.add(rechercherGroupeLabel);
        requestPanel.add(rechercherGroupeField);
        requestPanel.add(rechercherGroupeBtn);
        requestPanel.add(jouerLabel);
        requestPanel.add(jouerField);
        requestPanel.add(jouerBtn);

        /* The text area */
        
        textArea = new JTextArea(10, 40);
        textArea.setEditable(false);
        textArea.setText("Add sentences!\n");

        JScrollPane textScrollPane = new JScrollPane(textArea);
        
        /* The main panel */
        
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());
        mainPanel.add(toolBar, BorderLayout.NORTH);
        mainPanel.add(requestPanel, BorderLayout.CENTER);
        mainPanel.add(textScrollPane, BorderLayout.SOUTH);
        
        /* The main frame */
        
        setJMenuBar(menuBar);
        add(mainPanel);
        setPreferredSize(new Dimension(500, 600));
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }


    /*****************************************
     ********** Actions and Listeners ********
     *****************************************/

    public class AddSentence1Action extends AbstractAction
    {
        public AddSentence1Action()
        {
            super("Add Sentence 1");
        }
        public void actionPerformed(ActionEvent e)
        {
            textArea.append("Sentence 1\n");
        }
    }

    public class AddSentence2Action extends AbstractAction
    {   
        public AddSentence2Action()
        {
            super("Add Sentence 2");
        }
        public void actionPerformed(ActionEvent e)
        {
            textArea.append("Sentence 2\n");
        }
    }

    public class CloseAction extends AbstractAction
    {
        public CloseAction()
        {
            super("Close application");
        }
        public void actionPerformed(ActionEvent e)
        {
            System.exit(0);
        }
    }

    public class rechercherMultimediaListener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            String response = client.send("rechercher multimedia " + rechercherMultimediaField.getText());
            textArea.setText(response + "\n");
        }
    }

    public class rechercherGroupeListener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            String response = client.send("rechercher groupe " + rechercherGroupeField.getText());
            textArea.setText(response + "\n");
        }
    }

    public class jouerListener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            String response = client.send("jouer " + jouerField.getText());
            textArea.setText(response + "\n");
        }
    }


    /*****************************************
     *************** Main method *************
     *****************************************/

    /// Lit une requete depuis le Terminal, envoie cette requete au serveur,
    /// recupere sa reponse et l'affiche sur le Terminal.
    /// Noter que le programme bloque si le serveur ne repond pas.

    public static void main(String argv[])
    { 
        /* Connexion */

        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        if (argv.length >=1) host = argv[0];
        if (argv.length >=2) port = Integer.parseInt(argv[1]);
        
        try {
            client = new Client(host, port);
        }
        catch (Exception e) {
            System.err.println("Client: Couldn't connect to " + host + ":" + port);
            System.exit(1);
        }
    
        System.out.println("Client connected to " + host + ":" + port);

        /* Instanciation de MainFrame */
        
        MainFrame mainFrame = new MainFrame();
    }
}
