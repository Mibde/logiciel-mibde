#ifndef MEMBRE_HPP
#define MEMBRE_HPP

#include <wx/wx.h>
#include <vector>
#include "Personne.hpp"

class Membre : public wxStaticBoxSizer
{
public:
    Membre(wxPanel* panel_parent);

private:
    void NewMembre(wxCommandEvent& event);

    wxPanel* panel_parent;
    wxPanel* panel_membres;
    wxScrolledWindow* scrole_membres;
    wxBoxSizer* sizer_panel_membres;

    wxBoxSizer* sizer_membres;
    wxBoxSizer* sizer_scrole;
    wxBoxSizer* sizer_membres_button;
    wxButton* ajoute_article;
    std::vector<Personne*> membres;
};

#endif // MEMBRE_HPP
