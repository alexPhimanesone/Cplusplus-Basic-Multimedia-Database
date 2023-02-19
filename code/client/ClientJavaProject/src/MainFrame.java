import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class MainFrame extends JFrame
{
    private static final long serialVersionUID = 1L;

    /* Components */
    JTextArea textArea;

    public MainFrame()
    {
        /* The text area */
        
        textArea = new JTextArea(40, 80);
        textArea.setEditable(false);
        textArea.setText("Add sentences!\n");

        JScrollPane textScrollPane = new JScrollPane(textArea);
        
        /* The buttons panel */

        JButton btnAddSentence1 = new JButton("Add Sentence 1");
        btnAddSentence1.addActionListener(new AddSentence1Listener());

        JButton btnAddSentence2 = new JButton("Add Sentence 2");
        btnAddSentence2.addActionListener(new AddSentence2Listener());

        JButton btnClose = new JButton("Close application");
        btnClose.addActionListener(new CloseListener());

        JPanel buttonsPanel = new JPanel();
        buttonsPanel.setLayout(new GridLayout(1, 3));
        buttonsPanel.add(btnAddSentence1);
        buttonsPanel.add(btnAddSentence2);
        buttonsPanel.add(btnClose);

        /* The main panel */
        
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());
        mainPanel.add(textScrollPane, BorderLayout.CENTER);
        mainPanel.add(buttonsPanel, BorderLayout.SOUTH);

        /* The main frame */
        
        add(mainPanel);
        setSize(500, 600);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    /***********************************
     **********   LISTENERS   **********
     ***********************************/

    class AddSentence1Listener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            textArea.append("Sentence 1\n");
        }
    }

    class AddSentence2Listener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            textArea.append("Sentence 2\n");
        }
    }

    class CloseListener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            System.exit(0);
        }
    }
}
