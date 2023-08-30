--
-- PostgreSQL database dump
--

-- Dumped from database version 15.1 (Ubuntu 15.1-1.pgdg22.04+1)
-- Dumped by pg_dump version 15.1 (Ubuntu 15.1-1.pgdg22.04+1)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: article; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.article (
    typea character(60) NOT NULL
);


--
-- Name: contenu_vente; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.contenu_vente (
    nom_snack character(60) NOT NULL,
    date_et_heure timestamp without time zone NOT NULL,
    occurrence integer,
    prix double precision DEFAULT 0.0 NOT NULL,
    prix_achat double precision DEFAULT 0.0 NOT NULL
);


--
-- Name: historique_vente; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.historique_vente (
    date_et_heure timestamp without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


--
-- Name: personne; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.personne (
    nom character varying NOT NULL,
    prenom character varying NOT NULL,
    actif integer DEFAULT 1 NOT NULL
);


--
-- Name: peut_contenir; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.peut_contenir (
    categorie character(60) NOT NULL,
    nom_snack character varying(100) NOT NULL
);


--
-- Name: snack; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.snack (
    nom_snack character varying(100) NOT NULL,
    prix double precision NOT NULL,
    prix_achat double precision NOT NULL,
    description character varying,
    quantite integer NOT NULL,
    en_vente integer DEFAULT 1 NOT NULL,
    rupture integer NOT NULL,
    typea character(60) NOT NULL,
    chemin_vers_limage character varying NOT NULL
);


--
-- Name: statut; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.statut (
    categorie character(60) NOT NULL
);


--
-- Name: vendu_par; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.vendu_par (
    date_et_heure timestamp without time zone NOT NULL,
    nom character varying NOT NULL,
    prenom character varying NOT NULL
);


--
-- Data for Name: article; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.article VALUES ('boisson                                                     ');
INSERT INTO public.article VALUES ('snack                                                       ');
INSERT INTO public.article VALUES ('nouille                                                     ');
INSERT INTO public.article VALUES ('autre                                                       ');


--
-- Data for Name: contenu_vente; Type: TABLE DATA; Schema: public; Owner: -
--



--
-- Data for Name: historique_vente; Type: TABLE DATA; Schema: public; Owner: -
--



--
-- Data for Name: personne; Type: TABLE DATA; Schema: public; Owner: -
--



--
-- Data for Name: peut_contenir; Type: TABLE DATA; Schema: public; Owner: -
--



--
-- Data for Name: snack; Type: TABLE DATA; Schema: public; Owner: -
--



--
-- Data for Name: statut; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.statut VALUES ('halal                                                       ');
INSERT INTO public.statut VALUES ('casher                                                      ');
INSERT INTO public.statut VALUES ('vegan                                                       ');
INSERT INTO public.statut VALUES ('vegetarien                                                  ');
INSERT INTO public.statut VALUES ('recyclabe                                                   ');


--
-- Data for Name: vendu_par; Type: TABLE DATA; Schema: public; Owner: -
--



--
-- Name: article article_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.article
    ADD CONSTRAINT article_pkey PRIMARY KEY (typea);


--
-- Name: contenu_vente contenu_vente_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.contenu_vente
    ADD CONSTRAINT contenu_vente_pkey PRIMARY KEY (nom_snack, date_et_heure);


--
-- Name: historique_vente historique_vente_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.historique_vente
    ADD CONSTRAINT historique_vente_pkey PRIMARY KEY (date_et_heure);


--
-- Name: personne personne_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.personne
    ADD CONSTRAINT personne_pkey PRIMARY KEY (nom, prenom);


--
-- Name: peut_contenir peut_contenir_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.peut_contenir
    ADD CONSTRAINT peut_contenir_pkey PRIMARY KEY (categorie, nom_snack);


--
-- Name: snack snack_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.snack
    ADD CONSTRAINT snack_pkey PRIMARY KEY (nom_snack);


--
-- Name: statut statut_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.statut
    ADD CONSTRAINT statut_pkey PRIMARY KEY (categorie);


--
-- Name: vendu_par vendu_par_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.vendu_par
    ADD CONSTRAINT vendu_par_pkey PRIMARY KEY (date_et_heure, nom, prenom);


--
-- Name: contenu_vente contenu_vente_date_et_heure_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.contenu_vente
    ADD CONSTRAINT contenu_vente_date_et_heure_fkey FOREIGN KEY (date_et_heure) REFERENCES public.historique_vente(date_et_heure);


--
-- Name: contenu_vente contenu_vente_nom_snack_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.contenu_vente
    ADD CONSTRAINT contenu_vente_nom_snack_fkey FOREIGN KEY (nom_snack) REFERENCES public.snack(nom_snack);


--
-- Name: peut_contenir peut_contenir_categorie_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.peut_contenir
    ADD CONSTRAINT peut_contenir_categorie_fkey FOREIGN KEY (categorie) REFERENCES public.statut(categorie);


--
-- Name: peut_contenir peut_contenir_nom_snack_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.peut_contenir
    ADD CONSTRAINT peut_contenir_nom_snack_fkey FOREIGN KEY (nom_snack) REFERENCES public.snack(nom_snack);


--
-- Name: snack snack_typea_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.snack
    ADD CONSTRAINT snack_typea_fkey FOREIGN KEY (typea) REFERENCES public.article(typea);


--
-- Name: vendu_par vendu_par_date_et_heure_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.vendu_par
    ADD CONSTRAINT vendu_par_date_et_heure_fkey FOREIGN KEY (date_et_heure) REFERENCES public.historique_vente(date_et_heure);


--
-- Name: vendu_par vendu_par_nom_prenom_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.vendu_par
    ADD CONSTRAINT vendu_par_nom_prenom_fkey FOREIGN KEY (nom, prenom) REFERENCES public.personne(nom, prenom);


--
-- PostgreSQL database dump complete
--

